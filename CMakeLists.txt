cmake_minimum_required(VERSION 3.15)
project(nfs_recompiled LANGUAGES C CXX ASM)

# options
option(WITH_PEDANTIC_FPU "Compile pedantic FPU implementation" OFF)
option(WITH_MMX "Enable MMX support" ON)

# add compile definitions based on options
if(WITH_PEDANTIC_FPU)
    add_compile_definitions(WITH_PEDANTIC_FPU)
endif()
if(WITH_MMX)
    add_compile_definitions(WITH_MMX)
endif()

# Detect Windows target: covers native Windows (WIN32/MINGW), an explicit
# -DCMAKE_SYSTEM_NAME=Windows, and cross-compilation via a MinGW toolchain
# supplied directly with -DCMAKE_C_COMPILER=…/x86_64-w64-mingw32-gcc (in
# which case WIN32/MINGW may not yet be set if no toolchain file is used).
if(WIN32 OR MINGW OR CMAKE_SYSTEM_NAME STREQUAL "Windows"
        OR CMAKE_C_COMPILER MATCHES "mingw"
        OR CMAKE_CXX_COMPILER MATCHES "mingw")
    set(TARGET_WINDOWS TRUE)
else()
    set(TARGET_WINDOWS FALSE)
endif()

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror)
endif()

# When building for Windows we have a local copy of SDL2 under the
# `sdl2` subdirectory.  Point CMake at it so find_package() will
# locate the bundled config file automatically.
if(TARGET_WINDOWS)
    message(STATUS "Windows target detected – adding ${CMAKE_SOURCE_DIR}/sdl2/cmake to CMAKE_PREFIX_PATH for SDL2")
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/sdl2/cmake")
    set(SDL2_DIR "${CMAKE_SOURCE_DIR}/sdl2/cmake" CACHE PATH "SDL2 CMake directory")
endif()

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# prefer modern imported targets if available
if(TARGET SDL2::SDL2)
    set(SDL2_LIB_TARGET SDL2::SDL2)
else()
    include_directories(${SDL2_INCLUDE_DIRS})
    set(SDL2_LIB_TARGET ${SDL2_LIBRARIES})
endif()

# SDL2main provides the WinMain→main entry-point shim required on Windows.
# The modern config exposes it as a separate target; the legacy FindSDL2.cmake
# already folds it into SDL2_LIBRARIES, so we only add it on top for the
# imported-target path.
if(TARGET SDL2::SDL2main)
    set(SDL2_MAIN_TARGET SDL2::SDL2main)
else()
    set(SDL2_MAIN_TARGET "")
endif()

file(GLOB NFS2SE_DISASM_SOURCES
     "${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/*.cpp")
file(GLOB NFS2SE_DISASM_HEADERS
     "${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/*.h")

file(GLOB NFS3HP_DISASM_SOURCES
     "${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/*.cpp")
file(GLOB NFS3HP_DISASM_HEADERS
     "${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/*.h")

# ---------------------------------------------------------------------------
# core static library
# ---------------------------------------------------------------------------

file(GLOB LIB_CPP_SOURCES
     "${CMAKE_SOURCE_DIR}/src/lib/*.cpp"
     "${CMAKE_SOURCE_DIR}/src/lib/sdl-backend/*.cpp"
     "${CMAKE_SOURCE_DIR}/src/lib/winapi/*.cpp"
     "${CMAKE_SOURCE_DIR}/src/lib/winapi/ddraw/*.cpp"
     "${CMAKE_SOURCE_DIR}/src/lib/winapi/dinput/*.cpp"
     "${CMAKE_SOURCE_DIR}/src/lib/winapi/dsound/*.cpp")

# x87.asm provides 80-bit extended-precision FPU helpers and is only needed
# (and only supported) on Linux with WITH_PEDANTIC_FPU=ON.
if(WITH_PEDANTIC_FPU AND TARGET_WINDOWS)
    message(FATAL_ERROR
        "WITH_PEDANTIC_FPU is not supported on Windows: the x87 NASM helper "
        "relies on Linux-specific 80-bit long double ABI conventions.")
endif()

if(WITH_PEDANTIC_FPU AND NOT TARGET_WINDOWS)
    set(X87_OBJ "${CMAKE_CURRENT_BINARY_DIR}/x87.o")
    add_custom_command(
        OUTPUT ${X87_OBJ}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND nasm -f elf64 -o ${X87_OBJ} ${CMAKE_SOURCE_DIR}/src/lib/x87.asm
        DEPENDS ${CMAKE_SOURCE_DIR}/src/lib/x87.asm
        COMMENT "Assembling x87.asm (elf64, pedantic FPU)"
        VERBATIM
    )
    list(APPEND LIB_CPP_SOURCES ${X87_OBJ})
endif()

add_library(nfs_core STATIC ${LIB_CPP_SOURCES})
target_include_directories(nfs_core PRIVATE
    ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(nfs_core PRIVATE ${SDL2_MAIN_TARGET} ${SDL2_LIB_TARGET} OpenGL::GL)

# helper function for adding the game executables
function(add_game_exe name)
    # script and directories
    set(game_src_dir "${CMAKE_SOURCE_DIR}/src/${name}")

    # collect sources
    file(GLOB GAME_SOURCES "${game_src_dir}/*.cpp")

    # pick the hardcoded disasm set for this game
    if(name STREQUAL "nfs2se")
        set(DISASM_SOURCES ${NFS2SE_DISASM_SOURCES})
        set(DISASM_HEADERS ${NFS2SE_DISASM_HEADERS})
    elseif(name STREQUAL "nfs3hp")
        set(DISASM_SOURCES ${NFS3HP_DISASM_SOURCES})
        set(DISASM_HEADERS ${NFS3HP_DISASM_HEADERS})
    else()
        set(DISASM_SOURCES "")
        set(DISASM_HEADERS "")
    endif()

    # adding the headers to the executable source list is what makes CMake
    # aware that the custom command must run before compilation starts.
    add_executable(${name} ${GAME_SOURCES} ${DISASM_SOURCES} ${DISASM_HEADERS})
    set_source_files_properties(${DISASM_HEADERS} PROPERTIES HEADER_FILE_ONLY TRUE)
    target_include_directories(${name} PRIVATE
        ${game_src_dir}
        ${CMAKE_SOURCE_DIR}/src/${name}/disassembly
        ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(${name} PRIVATE ${SDL2_MAIN_TARGET} nfs_core ${SDL2_LIB_TARGET} OpenGL::GL)
    if(WITH_PEDANTIC_FPU)
        target_compile_definitions(${name} PRIVATE WITH_PEDANTIC_FPU)
    endif()
    if(WITH_MMX)
        target_compile_definitions(${name} PRIVATE WITH_MMX)
    endif()
endfunction()

add_game_exe(nfs2se)
add_game_exe(nfs3hp)
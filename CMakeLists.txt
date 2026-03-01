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

# find dependencies
find_package(Python3 COMPONENTS Interpreter REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# prefer modern imported target if available
if(TARGET SDL2::SDL2)
    set(SDL2_LIB_TARGET SDL2::SDL2)
else()
    include_directories(${SDL2_INCLUDE_DIRS})
    set(SDL2_LIB_TARGET ${SDL2_LIBRARIES})
endif()

# we hard‑code the list of generated disassembly sources rather than
# invoking the Python scripts at configure time.  This keeps the expensive
# generation step purely inside the build if you re-run the scripts later.

# Python source files that, when changed, should trigger regeneration
file(GLOB_RECURSE DISASM_PY_DEPS
    "${CMAKE_SOURCE_DIR}/disasm/*.py")

# explicit file lists for each game; update these manually whenever the
# generators produce new files
set(NFS2SE_DISASM_SOURCES
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/eacsnd.0.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/eacsnd.AUTO.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/eacsnd.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/eacsnd.DGROUP.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/eacsnd._edata.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/eacsnd._idata.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.0.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.10.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.11.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.12.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.13.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.14.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.15.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.16.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.17.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.18.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.19.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.1.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.20.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.21.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.22.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.23.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.24.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.25.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.26.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.27.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.28.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.29.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.2.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.30.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.31.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.32.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.33.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.34.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.35.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.36.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.3.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.4.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.5.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.6.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.7.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.8.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.9.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.AUTO.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.DGROUP.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se._idata.cpp
)

# header files produced alongside nfs2se sources (not compiled, but still outputs)
set(NFS2SE_DISASM_HEADERS
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/eacsnd.h
    ${CMAKE_SOURCE_DIR}/src/nfs2se/disassembly/nfs2se.h
)

# custom command: re-run disassemble_nfs2se.py if any .py dep changes or any
# output file is missing.
add_custom_command(
    OUTPUT ${NFS2SE_DISASM_SOURCES} ${NFS2SE_DISASM_HEADERS}
    COMMAND ${Python3_EXECUTABLE} "${CMAKE_SOURCE_DIR}/disassemble_nfs2se.py"
    DEPENDS "${CMAKE_SOURCE_DIR}/disassemble_nfs2se.py" ${DISASM_PY_DEPS}
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    COMMENT "Generating nfs2se disassembly sources"
    VERBATIM
)

set(NFS3HP_DISASM_SOURCES
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/eacsnd.0.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/eacsnd.1.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/eacsnd.2.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/eacsnd.3.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/eacsnd.AUTO.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/eacsnd.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/eacsnd.DGROUP.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/eacsnd._edata.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/eacsnd._idata.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.0.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.10.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.11.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.12.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.13.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.14.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.15.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.16.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.17.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.18.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.19.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.1.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.20.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.21.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.22.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.23.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.24.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.25.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.26.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.27.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.28.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.29.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.2.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.30.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.31.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.32.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.33.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.34.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.35.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.36.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.37.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.38.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.39.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.3.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.40.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.41.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.42.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.43.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.44.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.45.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.46.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.47.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.48.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.49.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.4.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.50.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.51.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.52.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.53.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.54.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.55.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.56.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.57.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.5.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.6.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.7.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.8.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.9.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.AUTO.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.DGROUP.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp._idata.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp._rsrc.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria.0.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria.1.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria.2.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria.3.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria.4.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria.5.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria.AUTO.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria.DGROUP.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria._edata.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria._idata.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a.0.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a.1.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a.2.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a.3.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a.4.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a.AUTO.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a.DGROUP.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a._edata.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a._idata.cpp
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a._rsrc.cpp
)

# header files produced alongside nfs3hp sources
set(NFS3HP_DISASM_HEADERS
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/eacsnd.h
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/nfs3hp.h
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/softtria.h
    ${CMAKE_SOURCE_DIR}/src/nfs3hp/disassembly/voodoo2a.h
)

# custom command: re-run disassemble_nfs3hp.py if any .py dep changes or any
# output file is missing.
add_custom_command(
    OUTPUT ${NFS3HP_DISASM_SOURCES} ${NFS3HP_DISASM_HEADERS}
    COMMAND ${Python3_EXECUTABLE} "${CMAKE_SOURCE_DIR}/disassemble_nfs3hp.py"
    DEPENDS "${CMAKE_SOURCE_DIR}/disassemble_nfs3hp.py" ${DISASM_PY_DEPS}
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    COMMENT "Generating nfs3hp disassembly sources"
    VERBATIM
)

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

set(X87_OBJ "${CMAKE_CURRENT_BINARY_DIR}/x87.o")
add_custom_command(
    OUTPUT ${X87_OBJ}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND nasm -f elf64 -o ${X87_OBJ} ${CMAKE_SOURCE_DIR}/src/lib/x87.asm
    DEPENDS ${CMAKE_SOURCE_DIR}/src/lib/x87.asm
    COMMENT "Assembling x87.asm"
    VERBATIM
)
list(APPEND LIB_CPP_SOURCES ${X87_OBJ})

add_library(nfs_core STATIC ${LIB_CPP_SOURCES})
target_include_directories(nfs_core PRIVATE
    ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(nfs_core PRIVATE ${SDL2_LIB_TARGET} OpenGL::GL)

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
    target_link_libraries(${name} PRIVATE nfs_core ${SDL2_LIB_TARGET} OpenGL::GL)
    if(WITH_PEDANTIC_FPU)
        target_compile_definitions(${name} PRIVATE WITH_PEDANTIC_FPU)
    endif()
    if(WITH_MMX)
        target_compile_definitions(${name} PRIVATE WITH_MMX)
    endif()
endfunction()

add_game_exe(nfs2se)
add_game_exe(nfs3hp)

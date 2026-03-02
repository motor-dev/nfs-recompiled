# Toolchain file for cross-compiling to 64-bit Windows using Clang
# targeting the MSVC ABI, with headers and libraries from a mounted
# Windows partition containing Visual Studio and the Windows 10 SDK.
#
# Prerequisites (Debian/Ubuntu):
#   sudo apt install clang-21 lld-21 clang-tools-21
#
# Required mount:
#   /opt/sysroots/win11  – a Windows installation with Visual Studio 2022
#                          and the Windows 10 SDK already installed.
#
# Usage:
#   cmake -B build -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-msvc-clang.cmake \
#         -DCMAKE_BUILD_TYPE=Release
#
# Or from the VS Code CMake Tools extension: set "cmake.toolchainFilePath" in
# settings.json (or choose it from the CMake: Select a Kit prompt).

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR AMD64)

# Pointer size must be stated explicitly so CMake package version checks
# (e.g. the bundled SDL2) work correctly without needing to execute a
# cross-compiled test binary on the host.
set(CMAKE_SIZEOF_VOID_P 8)

# ---------------------------------------------------------------------------
# Paths into the mounted Windows sysroot
# ---------------------------------------------------------------------------
set(WIN_SYSROOT "/opt/sysroots/win11")

# Visual Studio / MSVC CRT & STL
set(MSVC_BASE "${WIN_SYSROOT}/program files/microsoft visual studio/2022/community/vc/tools/msvc/14.44.35207")
set(MSVC_INCLUDE "${MSVC_BASE}/include")
set(MSVC_LIB     "${MSVC_BASE}/lib/x64")

# Windows 10 SDK
set(WINSDK_BASE "${WIN_SYSROOT}/program files (x86)/windows kits/10")
set(WINSDK_VER  "10.0.26100.0")

set(WINSDK_UCRT_INCLUDE  "${WINSDK_BASE}/include/${WINSDK_VER}/ucrt")
set(WINSDK_SHARED_INCLUDE "${WINSDK_BASE}/include/${WINSDK_VER}/shared")
set(WINSDK_UM_INCLUDE    "${WINSDK_BASE}/include/${WINSDK_VER}/um")
set(WINSDK_WINRT_INCLUDE "${WINSDK_BASE}/include/${WINSDK_VER}/winrt")

set(WINSDK_UCRT_LIB "${WINSDK_BASE}/lib/${WINSDK_VER}/ucrt/x64")
set(WINSDK_UM_LIB   "${WINSDK_BASE}/lib/${WINSDK_VER}/um/x64")

# ---------------------------------------------------------------------------
# Compilers & tools  (LLVM / Clang, MSVC-compatible driver)
# ---------------------------------------------------------------------------
set(CMAKE_C_COMPILER   /usr/bin/clang-cl-21)
set(CMAKE_CXX_COMPILER /usr/bin/clang-cl-21)
set(CMAKE_LINKER        /usr/bin/lld-link-21)
set(CMAKE_RC_COMPILER   /usr/bin/llvm-rc-21)
set(CMAKE_AR            /usr/bin/llvm-lib-21)
set(CMAKE_MT            /usr/bin/llvm-mt-21)

# Tell CMake that clang-cl is an MSVC-like compiler so it generates the
# right flags (/O2 instead of -O2, etc.).
set(CMAKE_C_COMPILER_ID   "Clang")
set(CMAKE_CXX_COMPILER_ID "Clang")
set(CMAKE_C_SIMULATE_ID   "MSVC")
set(CMAKE_CXX_SIMULATE_ID "MSVC")

# Target triple
set(CLANG_TARGET "x86_64-pc-windows-msvc")

# ---------------------------------------------------------------------------
# Compiler flags  – system include paths via /imsvc (MSVC-style -isystem)
# ---------------------------------------------------------------------------
set(_CLANG_IMSVC_FLAGS
    "--target=${CLANG_TARGET}"
    "-D_CRT_SECURE_NO_WARNINGS=1"
    "/imsvc\"${MSVC_INCLUDE}\""
    "/imsvc\"${WINSDK_UCRT_INCLUDE}\""
    "/imsvc\"${WINSDK_SHARED_INCLUDE}\""
    "/imsvc\"${WINSDK_UM_INCLUDE}\""
    "/imsvc\"${WINSDK_WINRT_INCLUDE}\""
)
string(JOIN " " _CLANG_IMSVC_FLAGS_STR ${_CLANG_IMSVC_FLAGS})

set(CMAKE_C_FLAGS_INIT   "${_CLANG_IMSVC_FLAGS_STR}")
set(CMAKE_CXX_FLAGS_INIT "${_CLANG_IMSVC_FLAGS_STR}")

# ---------------------------------------------------------------------------
# Linker flags  – library search paths via /LIBPATH
# ---------------------------------------------------------------------------
set(_LINKER_FLAGS
    "/LIBPATH:\"${MSVC_LIB}\""
    "/LIBPATH:\"${WINSDK_UCRT_LIB}\""
    "/LIBPATH:\"${WINSDK_UM_LIB}\""
)
string(JOIN " " _LINKER_FLAGS_STR ${_LINKER_FLAGS})

set(CMAKE_EXE_LINKER_FLAGS_INIT    "${_LINKER_FLAGS_STR}")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "${_LINKER_FLAGS_STR}")
set(CMAKE_MODULE_LINKER_FLAGS_INIT "${_LINKER_FLAGS_STR}")
set(CMAKE_STATIC_LINKER_FLAGS_INIT "")

# ---------------------------------------------------------------------------
# CMake find-package / find-library search configuration
# ---------------------------------------------------------------------------
set(CMAKE_FIND_ROOT_PATH "${MSVC_BASE}" "${WINSDK_BASE}")

# Search programs on the host, but libraries/headers on the target.
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Toolchain file for cross-compiling to 64-bit Windows using the
# x86_64-w64-mingw32 cross-compiler available on Debian/Ubuntu:
#
#   sudo apt install gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64
#
# Usage:
#   cmake -B build -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-mingw64.cmake \
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

# Cross-compiler executables
set(CMAKE_C_COMPILER   /usr/bin/x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/x86_64-w64-mingw32-g++)
set(CMAKE_RC_COMPILER  /usr/bin/x86_64-w64-mingw32-windres)

# Where to look for target-system headers/libs (restricts CMake from
# accidentally picking up the host's native libraries).
set(CMAKE_FIND_ROOT_PATH  /usr/x86_64-w64-mingw32)

# Search programs on the host, but libraries/headers on the target.
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

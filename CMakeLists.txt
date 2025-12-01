cmake_minimum_required(VERSION 3.17)
project(Spelunky2SeedFinder)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

execute_process(
  COMMAND git describe --always --dirty=-modified
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_VERSION
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_compile_definitions("GIT_VERSION=${GIT_VERSION}")
add_compile_definitions(_ITERATOR_DEBUG_LEVEL=0)
add_compile_definitions(NOMINMAX)

# Fix MSVC 19.40 crash with mutex due to spelunky using an old redist (mscvp140.dll)
# Related links: https://github.com/microsoft/STL/releases/tag/vs-2022-17.10 | https://github.com/actions/runner-images/issues/10004
add_compile_definitions(_DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR)

# Temp fix for the new MSVC tools requiring minimum clang 18, for the time being we're staying on clang 17
add_compile_definitions(_ALLOW_COMPILER_AND_STL_VERSION_MISMATCH)

set(FMT_MASTER_PROJECT OFF)
option(BUILD_OVERLUNKY CACHE OFF)
option(BUILD_INFO_DUMP CACHE OFF)
option(BUILD_SPEL2_DLL CACHE OFF)
add_subdirectory(3rdParty/overlunky)
add_subdirectory(injector)
add_subdirectory(injected)

if (MSVC)
  add_compile_options(/bigobj)
endif()

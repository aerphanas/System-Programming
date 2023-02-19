cmake_minimum_required(VERSION 3.5)

project(sysutils LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)

add_executable(sysinfo.bin sysinfo.c)
add_executable(os-release.bin os-release.c)
add_executable(clipboard.bin clipboard.c)
add_executable(time.bin time.c)

find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBX REQUIRED x11)

target_compile_options(clipboard.bin PRIVATE -Wall)
target_link_libraries(clipboard.bin PRIVATE m ${LIBX_LIBRARIES})
target_include_directories(clipboard.bin PRIVATE ${LIBX_INCLUDE_DIRS})

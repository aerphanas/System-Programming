cmake_minimum_required(VERSION 3.5)

project(example LANGUAGES C)

add_executable(example example.c)

install(TARGETS example
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBPW REQUIRED libpipewire-0.3)

target_compile_options(example PRIVATE -Wall)
target_link_libraries(example PRIVATE m ${LIBPW_LIBRARIES})
target_include_directories(example PRIVATE ${LIBPW_INCLUDE_DIRS})

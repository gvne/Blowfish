cmake_minimum_required(VERSION 3.0)

include(ExternalProject)

project(blowfish)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_DEBUG_POSTFIX d)

option(blowfish_enable_tests "Build Unit tests" ON)

if (${blowfish_enable_tests})
  enable_testing()
  set(gtest_install_dir ${CMAKE_BINARY_DIR}/googletest-install)
  ExternalProject_Add(external_googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "718fd88d8f145c63b8cc134cf8fed92743cc112f"
    CMAKE_ARGS
      "-Dgtest_force_shared_crt=ON"
      "-DCMAKE_INSTALL_PREFIX=${gtest_install_dir}"
  )
  link_directories("${gtest_install_dir}/lib")
endif ()

set(src "${CMAKE_SOURCE_DIR}/src")
include_directories(${src})
add_subdirectory("./src")

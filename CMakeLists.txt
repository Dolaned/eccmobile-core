# ECC Build System
#
# This CMakeLists.txt is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.

# CMake version
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# Declare project
project(ECCSPV C CXX)

# Setup sources
file(GLOB DIR_SOURCES ${ECCSPV_SOURCE_DIR}/*.c)
file(GLOB DIR_HEADERS ${ECCSPV_SOURCE_DIR}/*.c)

#
# secp256k1 - uses the original autotools
#
include(ExternalProject)
ExternalProject_Add(secp256k1
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/deps/secp256k1
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/secp256k1
  BUILD_IN_SOURCE 0
  CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/secp256k1/configure --prefix=<INSTALL_DIR>
  BUILD_COMMAND ${MAKE}
  INSTALL_COMMAND ""
)
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/secp256k1
  ${CMAKE_CURRENT_SOURCE_DIR}/secp256k1/src
  ${CMAKE_CURRENT_SOURCE_DIR}/secp256k1/include
)

#
# setup all the libraries
#
set(ECC_LIBS
  ${CMAKE_CURRENT_BINARY_DIR}/deps/secp256k1/src/secp256k1-build/.libs/libsecp256k1.a
)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

#--------------------------------------------------------------------------------
#  CMake's way of creating an executable
add_executable(spvtest
  ${DIR_HEADERS}
  ${DIR_SOURCES}
)
add_dependencies(spvtest secp256k1)

# Link the libraries into the binary
target_link_libraries(spvtest ${ECC_LIBS} Threads::Threads m)

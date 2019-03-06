project(SHAHashTestUtil C CXX)
cmake_minimum_required(VERSION 3.0)

#set some custom options and default values
set(ARCHSUFFIX ".${CMAKE_SYSTEM_PROCESSOR}")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif(NOT CMAKE_BUILD_TYPE)

#set defaults
set(EXELINKFLAGS "")
set(OPTFLAGS "")

#setup RPATH and build directories
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_USE_RELATIVE_PATHS TRUE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

set(CMAKE_INSTALL_RPATH "./lib${ARCHSUFFIX}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/lib${ARCHSUFFIX}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/lib${ARCHSUFFIX}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")

file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/..")

#set flags for gcc
if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
  #optional flags for g++ compiler
  set(OPTFLAGS "")
  #general compiler flags for g++ compiler
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -fpermissive -fno-exceptions -Wall -Wextra -Wshadow -Wstrict-overflow=5 -Wwrite-strings -Winit-self -Wmissing-include-dirs -Wcast-qual -Wcast-align -Wconversion -Wlogical-op -Wpacked -Wredundant-decls -Winline -Wdisabled-optimization -Woverlength-strings -Wfloat-equal -Wswitch-default -Wno-missing-field-initializers ${OPTFLAGS}")
  #set build-type dependent additional flags
  set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
  set(CMAKE_CXX_FLAGS_DEBUG "-O0 -DDEBUG -ggdb")
  set(EXELINKFLAGS "-Wl,-rpath-link,'${CMAKE_LIBRARY_OUTPUT_DIRECTORY}'")
endif()

#test util
add_executable(HashTestUtil main.cpp ../sha1.c ../hmac.c)

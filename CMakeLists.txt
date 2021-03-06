# CMakeLists.txt
#
# Purpose: to compile tucano examples.
# If you want to simply use tucano, you don't need this file; just get the header files.
#
# List of dependencies common to all examples:
#  - glew
#  - eigen3
#  - an OpenGL 4.3+ compatible driver
#  - pkg-config
#
# List of dependencies of some examples:
#  - Qt5
#  - GLFW

cmake_minimum_required(VERSION 2.8.12)
project(tucano C CXX)

# Tucano directories.
#
# Where executables of the examples are put.
set(TUCANO_BINARY_DIR "${PROJECT_SOURCE_DIR}/bin")
set(TUCANO_DOCUMENTATION_DIR "${PROJECT_SOURCE_DIR}/doc")
set(TUCANO_EFFECTS_DIR "${PROJECT_SOURCE_DIR}/effects")
set(TUCANO_SAMPLES_DIR "${PROJECT_SOURCE_DIR}/samples")
set(TUCANO_SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(OSTYPE "$ENV{OSTYPE}")
if ("${OSTYPE}" MATCHES "FreeBSD")
	message("-- FreeBSD Operational System")
	message("-- FreeBSD Configuration")
	set(FREEBSD_INCLUDE_DIR "/usr/local/include")
	set(FREEBSD_LIB_DIR "/usr/local/lib")
	set(FREEBSD_LDFLAGS "-L${FREEBSD_LIB_DIR}")
	message("-- FREBSD_INCLUDE_DIR ${FREEBSD_INCLUDE_DIR}")
	message("-- FREBSD_LIB_DIR ${FREEBSD_LIB_DIR}")
	message("-- FREBSD_LDFLAGS ${FREEBSD_LDFLAGS}")
endif()

# Build options.
option(DOC "build documentation" ON)
option(SAMPLES "build samples" ON)



find_package(GLEW REQUIRED)
if(NOT GLEW_FOUND)
  message(SEND_ERROR "GLEW not found on your system.")
endif()

find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
  message(SEND_ERROR "OpenGL not found on your system.")
endif()

# Qt5.
find_package(Qt5OpenGL)
find_package(Qt5Widgets)
if (Qt5_POSITION_INDEPENDENT_CODE)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Eigen 3.
# pkg-config is used so we don't hard-code the location of eigen.
find_package(PkgConfig)
if(NOT PKG_CONFIG_FOUND)
    set( EIGEN3_INCLUDE_DIRS "$ENV{EIGEN3_INCLUDE_DIR}" )
    if( NOT EIGEN3_INCLUDE_DIRS )
    message( SEND_ERROR "pkg-config not found on your system. Please point the environment variable EI    GEN3_INCLUDE_DIR to the include directory of your Eigen3 installation.")
endif()
else()
    pkg_check_modules(EIGEN3 REQUIRED eigen3)
endif()


include_directories(
  ${EIGEN3_INCLUDE_DIRS}
  ${GLEW_INCLUDE_DIRS}
  ${OPENGL_INCLUDE_DIR}
  ${Qt5Widgets_INCLUDE_DIRS}
  ${Qt5OpenGL_INCLUDE_DIRS}
  ${TUCANO_EFFECTS_DIR}
  ${TUCANO_SRC_DIR}
  ${FREEBSD_INCLUDE_DIR}
  )

file(
  GLOB TUCANO_SOURCES
  "${TUCANO_SRC_DIR}/*.hpp"
  )

file(
  GLOB TUCANO_SOURCES_UTILS
  "${TUCANO_SRC_DIR}/utils/*.hpp"
  )

add_library(
  TUCANO_LIBRARY OBJECT
  ${TUCANO_SOURCES}
  ${TUCANO_SOURCES_UTILS}
  ${FREEBSD_LIB_INCLUDE}
  )

install(
  FILES ${TUCANO_SOURCES}
  DESTINATION "include/tucano"
  )

install(
  FILES ${TUCANO_SOURCES_UTILS}
  DESTINATION "include/tucano/utils"
  )

if(DOC)
  add_subdirectory(${TUCANO_DOCUMENTATION_DIR})
endif()

if(SAMPLES)
  # Put executable / compiled files in the binary directory.
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TUCANO_BINARY_DIR})
	set(CMAKE_LD_FLAGS "-L/usr/local/lib")
  add_subdirectory(${TUCANO_SAMPLES_DIR})
endif()

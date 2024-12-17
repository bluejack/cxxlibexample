cmake_minimum_required(VERSION 3.15)
project(CXXLibExample LANGUAGES CXX)

# Define project-wide properties
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set architecture-specific output directories
set(ARCH_DIR "${CMAKE_SYSTEM_PROCESSOR}")

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${ARCH}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${ARCH}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${ARCH}/bin)

# Define include directories
include_directories(${CMAKE_SOURCE_DIR}/include) # Public headers
include_directories(${CMAKE_SOURCE_DIR}/src)     # Private headers

set(CXXLE_PUBLIC_HEADERS "include/cxxle.h")
file(GLOB CXXLE_SOURCES "src/*.cpp")

# Create the static libraries
add_library(cxxle_static STATIC ${CXXLE_SOURCES})
set_target_properties(cxxle_static PROPERTIES OUTPUT_NAME cxxle)
add_library(cxxle_shared SHARED ${CXXLE_SOURCES})
set_target_properties(cxxle_shared PROPERTIES OUTPUT_NAME cxxle)

# Linker settings
target_compile_definitions(cxxle_shared PRIVATE EXPORT_CXXLE)
target_compile_definitions(cxxle_static PRIVATE EXPORT_CXXLE)

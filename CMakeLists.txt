
cmake_minimum_required(VERSION 3.15)
project(CXXLibExample LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect sources and headers
file(GLOB CXXLE_PUBLIC_HEADERS "include/*.h")
file(GLOB CXXLE_SOURCES "src/*.cpp")

# Add the static library
add_library(cxxle_static STATIC ${CXXLE_SOURCES})
target_include_directories(cxxle_static PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
set_target_properties(cxxle_static PROPERTIES OUTPUT_NAME cxxle)

# Add the shared library
add_library(cxxle_shared SHARED ${CXXLE_SOURCES})
target_include_directories(cxxle_shared PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
set_target_properties(cxxle_shared PROPERTIES OUTPUT_NAME cxxle)

# Install targets
install(TARGETS cxxle_static cxxle_shared
        EXPORT CXXLibExampleTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
install(FILES ${CXXLE_PUBLIC_HEADERS} DESTINATION include)
export(TARGETS cxxle_static cxxle_shared FILE CXXLibExampleConfig.cmake)

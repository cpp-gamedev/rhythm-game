cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
	message(FATAL_ERROR "In Source Builds Not Allowed")
endif()

set(BUILD_CONFIG Debug)
set(CMAKE_BUILD_TYPE ${BUILD_CONFIG})
set(NAME rhtyhm-game)
set(SFML_VERSIN 2.5.1)
project(${NAME})

find_package(SFML ${SFML_VERSION} COMPONENTS graphics REQUIRED)
add_executable(${NAME} src/main.cpp)

target_link_libraries(${NAME} PUBLIC sfml-graphics sfml-window sfml-system)

set(COMPILE_OPTIONS -Wextra -Werror=return-type)
target_compile_options(${NAME} PUBLIC ${COMPILE_OPTIONS})

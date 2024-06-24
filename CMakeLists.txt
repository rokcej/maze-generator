cmake_minimum_required(VERSION 3.14)

project(maze-generator)

add_executable(${PROJECT_NAME} "src/main.cpp")

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_options(${PROJECT_NAME} PUBLIC
	# $<$<CXX_COMPILER_ID:MSVC>:/W4> # /WX
	# $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic> # -Werror
)

add_subdirectory(lib/raylib)

target_include_directories(${PROJECT_NAME}
	PRIVATE .
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE raylib
)

cmake_minimum_required(VERSION 3.22)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(inc)
include_directories(./libft/inc)
add_subdirectory(./libft)

add_executable(minishell
		src/main.c
		src/0_init/input.c src/0_init/signals.c
		src/1_parser/pre_parsing.c
		src/1_parser/parsing.c
		src/1_parser/pipe_redirect.c
		src/1_parser/limiter.c src/1_parser/post_parser.c src/1_parser/dollar.c)

set(CMAKE_C_FLAGS  "-lreadline" )

target_link_libraries(minishell libft)
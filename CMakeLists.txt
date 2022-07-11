cmake_minimum_required(VERSION 3.22)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(inc)
include_directories(./libft/inc)
add_subdirectory(./libft)

add_executable(minishell
		src/main.c
		src/0_init/input.c src/0_init/signals.c
		src/1_parser/pre_parsing.c src/1_parser/parsing.c src/1_parser/pipe_redirect.c
		src/1_parser/limiter.c src/1_parser/post_parser.c src/1_parser/dollar.c
		src/_utils/cleaning.c src/_utils/srt_cmd.c src/_utils/support.c src/_utils/utils.c
		src/env/export_env.c src/env/init_env.c src/env/u_env.c
		src/pipe/pipes.c src/pipe/u_pipes.c
		src/exec/exec.c src/exec/cmd_arr.c
		src/cmd/cd.c src/cmd/echo.c src/cmd/env.c src/cmd/exit.c src/cmd/export.c src/cmd/pwd.c src/cmd/unset.c)

set(CMAKE_C_FLAGS  "-lreadline" )

target_link_libraries(minishell libft)
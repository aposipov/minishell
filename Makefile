

NAME = 		minishell
LIBFT_A = 	libft/libft.a
CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror
FLAGS =		-lreadline
INCFLAG = 	-I ./inc/\
 			-I ./libft/inc
HEADER = 	./inc/

SRC = 		src/main.c\
            src/1_parser/pre_parsing.c src/1_parser/parsing.c src/1_parser/pipe_redirect.c\
            src/1_parser/limiter.c src/1_parser/post_parser.c src/1_parser/dollar.c\
            src/_utils/cleaning.c src/_utils/srt_cmd.c src/_utils/support.c src/_utils/utils.c\
            src/env/export_env.c src/env/init_env.c src/env/u_env.c\
            src/pipe/pipes.c src/pipe/u_pipes.c\
            src/exec/exec.c src/exec/cmd_arr.c\
            src/cmd/cd.c src/cmd/echo.c src/cmd/env.c\
            src/cmd/exit.c src/cmd/export.c src/cmd/pwd.c src/cmd/unset.c

OBJ = 		$(patsubst %.c, %.o, $(SRC))

RED= \033[4;31m
GREEN= \033[0;32m
NC= \033[0;0m

.PHONY:	all clean fclean re norm

all:		$(LIBFT_A) $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(FLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)
			@echo -e "$(GREEN)\t\n Minishel compiled! \n $(NC)"

$(LIBFT_A):
			make -C libft/

%.o : %.c 	Makefile $(HEADER)
			$(CC) $(INCFLAG) $(CFLAGS) -c $< -o $@

clean:
			make -C libft clean
			rm -f $(OBJ)
			@echo -e "$(RED)*.o files is clean!$(NC)"

fclean:		clean
			make -C libft fclean
			rm -f $(NAME)
			@echo -e "$(RED)All files is clean!$(NC)"

re:			fclean all

norm:
			@norminette $(HEADER) $(SRC)
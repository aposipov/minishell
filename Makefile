

NAME = 		minishell
LIBFT_A = 	libft/libft.a
CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror
FLAGS =		-lreadline
INCFLAG = 	-I ./inc/\
 			-I ./libft/inc
HEADER = 	./inc/

SRC = 		./src/main.c\
			./src/0_init/input.c ./src/0_init/signals.c

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
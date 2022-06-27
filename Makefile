

NAME = 		minishell
LIBFT_A = 	libft/libft.a
CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror
INCFLAG = 	-I ./inc/\
 			-I ./libft/inc
HEADER = 	./inc/

SRC = 		./src/main.c

OBJ = 		$(patsubst %.c, %.o, $(SRC))

RED= \033[4;31m
GREEN= \033[0;32m
NC= \033[0;0m

.PHONY:	all clean fclean re norm

all:		$(LIBFT_A) $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)
			@echo -e "$(GREEN)\t\n Minishel compiled! \n $(NC)"

$(LIBFT_A):
			make -C libft/

%.o : %.c 	Makefile $(HEADER)
			$(CC) $(INCFLAG) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)
			@echo -e "$(RED)*.o files is clean!$(NC)"

fclean:		clean
			rm -f $(NAME)
			make -C libft fclean
			@echo -e "$(RED)All files is clean!$(NC)"

re:			fclean all

norm:
			@norminette $(HEADER) $(SRC)
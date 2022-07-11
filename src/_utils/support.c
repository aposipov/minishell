//
// Created by user on 11.07.22.
//

#include "minishell.h"

void	err_msg(char *str)
{
	ft_putstr_fd(str + 1, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
}

void	sup_dup(int *fd)
{
	try_dup2(fd[1], 1);
	try_dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
}
//
// Created by user on 11.07.22.
//

#include "minishell.h"



void	try_free(void *target)
{
	if (target == NULL)
		return ;
	free(target);
	target = NULL;
}

void	try_free3(void *a, void *b, void *c)
{
	try_free(a);
	try_free(b);
	try_free(c);
}

char	**free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return (NULL);
	while (arr[i] != NULL)
	{
		try_free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	try_free(arr);
	arr = NULL;
	return (arr);
}

void	exit_error(char *str, int code)
{
	ft_putendl_fd(str, 2);
	exit (code);
}

void	cleaning(void)
{
	t_list	*tmp;

	while (g_shell.cmd)
	{
		ft_lstclear(&(((t_command *)g_shell.cmd->content)->argv), free);
		ft_lstclear(&(((t_command *)g_shell.cmd->content)->redirect), free);
		tmp = g_shell.cmd->next;
		ft_lstdelone(g_shell.cmd, free);
		g_shell.cmd = tmp;
	}
	g_shell.cmd = NULL;
	ft_lstadd_back(&g_shell.cmd, ft_lstnew((void *)command_new()));
}

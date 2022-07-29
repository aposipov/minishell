/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:46:36 by lchristi          #+#    #+#             */
/*   Updated: 2022/07/29 18:46:58 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tfree(void *target)
{
	if (target == NULL)
		return ;
	free(target);
	target = NULL;
}

void	tfree3(void *a, void *b, void *c)
{
	tfree(a);
	tfree(b);
	tfree(c);
}

char	**free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return (NULL);
	while (arr[i] != NULL)
	{
		tfree(arr[i]);
		arr[i] = NULL;
		i++;
	}
	tfree(arr);
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

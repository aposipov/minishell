/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:48:20 by lchristi          #+#    #+#             */
/*   Updated: 2022/07/29 18:48:28 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	status_handler(void)
{
	if (WIFEXITED(g_shell.result))
		g_shell.result = WEXITSTATUS(g_shell.result);
	else if (WIFSIGNALED(g_shell.result))
	{
		g_shell.result = 128 + WTERMSIG(g_shell.result);
		ft_putchar_fd('\r', 2);
	}
}

int	tdup(int fd)
{
	int	dupp;

	dupp = dup(fd);
	if (dupp == -1)
		exit_error(strerror(errno), 1);
	return (dupp);
}

int	tdup2(int fd, int fd2)
{
	int	dupp;

	dupp = dup2(fd, fd2);
	if (dupp == -1)
		exit_error(strerror(errno), 1);
	return (dupp);
}

char	*mod_strjoin_gnl(char *s1, char *s2)
{
	size_t	size;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(size);
	if (join == NULL)
		return (NULL);
	join[size - 1] = '\0';
	ft_memcpy(join, s1, ft_strlen(s1));
	ft_memcpy(join + ft_strlen(s1), s2, ft_strlen(s2));
	free (s1);
	s1 = NULL;
	return (join);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:42:39 by lchristi          #+#    #+#             */
/*   Updated: 2022/07/29 18:42:49 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	signaled(int *pip, char *limiter)
{
	ft_putchar_fd('\r', 2);
	close(pip[0]);
	close(pip[1]);
	try_free(limiter);
}

static void	limiter_child(int *pip, char *limiter)
{
	char	*input;

	signal(SIGINT, SIG_DFL);
	close (pip[0]);
	while (1)
	{
		input = readline("> ");
		if (!input || !ft_strncmp(input, limiter, ft_strlen(limiter) + 1))
		{
			try_free(input);
			exit(0);
		}
		ft_putendl_fd(input, pip[1]);
	}
}

char	*limiter_handler(char *rd, char *limiter)
{
	int		pip[2];
	pid_t	pid;

	try_free(rd);
	pipe(pip);
	pid = fork();
	if (pid == 0)
		limiter_child(pip, limiter);
	else
	{
		waitpid(pid, &g_shell.signal, 0);
		if (WIFSIGNALED(g_shell.result))
		{
			g_shell.signal = 1;
			signaled(pip, limiter);
			return (NULL);
		}
		if (WIFEXITED(g_shell.result))
			g_shell.result = WEXITSTATUS(g_shell.result);
	}
	close(pip[1]);
	limiter = ft_itoa(pip[0]);
	if (limiter == NULL)
		exit_error("Malloc error", -1);
	return (limiter);
}


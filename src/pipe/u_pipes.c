/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_pipes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <lchristi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:45:13 by lchristi          #+#    #+#             */
/*   Updated: 2022/07/29 18:45:36 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	*init_pipes(int argc, t_pipex *pipex, int *a, int *b)
{
	pid_t	*pid;

	pipex->cmd = g_shell.cmd;
	pipex->flag = 0;
	pipex->iter = 0;
	pipex->c_pipe = argc;
	pid = malloc(sizeof(pid_t) * pipex->c_pipe);
	if (pid == NULL)
		exit_error("Error malloc", -1);
	a[0] = 0;
	a[1] = 0;
	b[0] = 0;
	b[1] = 0;
	return (pid);
}

void	closer_pipes(int *a, int *b)
{
	if (a[0])
		close(a[0]);
	if (b[1])
		close(b[1]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <lchristi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:44:44 by lchristi          #+#    #+#             */
/*   Updated: 2022/07/29 18:45:06 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child(int flag, t_pipex *pipex, int *a, int *b)
{
	if (!flag && pipex->iter == 0)
	{
		close(a[0]);
		tdup2(a[1], 1);
		close(a[1]);
	}
	else if (!flag)
	{
		tdup2(b[0], 0);
		close(a[0]);
		tdup2(a[1], 1);
	}
	else if (flag)
	{
		tdup2(a[0], 0);
		close(a[0]);
		close(b[0]);
		tdup2(b[1], 1);
	}
}

static void	parent(int flag, t_list *cmd, int *a, int *b)
{
	if (!flag && !cmd->next)
		closer_pipes(a, b);
	else if (flag && !cmd->next)
	{
		if (a[1])
			close(a[1]);
		if (b[0])
			close(b[0]);
	}
	else if (!flag)
	{
		if (b[0])
			close(b[0]);
		close(a[1]);
	}
	else
	{
		if (a[0])
			close(a[0]);
		if (b[1])
			close(b[1]);
	}
}

static void	procces_pipe(t_pipex *pipex, int *a, int *b, pid_t *pid)
{
	pid[pipex->iter] = fork();
	if (!pid[pipex->iter])
	{
		if (!pipex->cmd->next)
		{
			if (!pipex->flag)
				tdup2(b[0], 0);
			else
				tdup2(a[0], 0);
			executing(pipex->cmd);
		}
		else
			child(pipex->flag, pipex, a, b);
		executing(pipex->cmd);
	}
	else
	{
		parent(pipex->flag, pipex->cmd, a, b);
		if (!pipex->flag && pipex->cmd->next)
			pipex->flag = 1;
		else if (pipex->flag && pipex->cmd->next)
			pipex->flag = 0;
	}
}

static void	if_have_next(t_pipex *pipex, int *a, int *b)
{
	if (pipex->cmd->next)
	{
		if (!pipex->flag)
			pipe(a);
		else
			pipe(b);
	}
}

void	pipes(int argc)
{
	int		a[2];
	int		b[2];
	t_pipex	pipex;
	pid_t	*pid;

	pid = init_pipes(argc, &pipex, a, b);
	while (pipex.cmd)
	{
		if_have_next(&pipex, a, b);
		procces_pipe(&pipex, a, b, pid);
		pipex.cmd = pipex.cmd->next;
		pipex.iter++;
	}
	pipex.iter = 0;
	while (pipex.iter < pipex.c_pipe)
	{
		waitpid(pid[pipex.iter], &g_shell.result, 0);
		status_handler();
		pipex.iter++;
	}
	try_free(pid);
}

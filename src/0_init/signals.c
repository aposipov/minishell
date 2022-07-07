//
// Created by user on 07.07.22.
//

#include "minishell.h"

/* C-D how it should work? */

void	int_handler(int siq)
{
	(void)siq;
//	if (sig == SIGINT)
//	{
//		ft_putstr_fd("\n", 1);
//		rl_on_new_line();
//		rl_replace_line("", 0);
//		if (g_termflag.is_reading)
//		{
//			g_termflag.last_exit_status = 1;
//			rl_redisplay();
//		}
//		else
//			g_termflag.last_exit_status = 130;
//	}
//	if (g_global.is_runing)
//		return ;
//	g_global.exit_status = 128 + siq;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	quit_handler(int sig)
{
	(void)sig;
//	if (sig == SIGQUIT)
//	{
//		if (*rl_line_buffer && !g_termflag.is_reading)
//		{
//			g_termflag.last_exit_status = 131;
//			ft_putendl_fd("Quit: 3", 1);
//		}
//		else
//		{
//			rl_on_new_line();
//			rl_redisplay();
//		}
//	}
	exit(0);
}

void	init_signals(void)
{
	signal(SIGINT, &int_handler);
	signal(SIGQUIT, &quit_handler);
}

void	sigreset(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
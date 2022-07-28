//
// Created by user on 07.07.22.
//

#include "minishell.h"

/* C-D how it should work? */

static void	int_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', 2);
		rl_replace_line("", 2);
		rl_on_new_line();
		rl_redisplay();
		g_shell.result = 1; //
	}
}

void	init_signals(void)
{
	signal(SIGINT, &int_handler);
	signal(SIGQUIT, SIG_IGN);
}

//void	sigreset(void)
//{
//	signal(SIGINT, SIG_DFL);
//	signal(SIGQUIT, SIG_DFL);
//}
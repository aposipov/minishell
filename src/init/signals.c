/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:39:14 by lchristi          #+#    #+#             */
/*   Updated: 2022/07/29 18:40:03 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	int_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', 2);
		rl_replace_line("", 2);
		rl_on_new_line();
		rl_redisplay();
		g_shell.result = 1;
	}
}

void	init_signals(void)
{
	signal(SIGINT, &int_handler);
	signal(SIGQUIT, SIG_IGN);
}

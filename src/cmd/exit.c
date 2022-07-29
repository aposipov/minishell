/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <lchristi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:30:00 by lchristi          #+#    #+#             */
/*   Updated: 2022/07/29 18:30:44 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_sup(char **argv)
{
	int	i;

	ft_putendl_fd("exit", 2);
	i = 0;
	while (ft_isdigit(argv[1][i]))
		i++;
	if (argv[1][i] != '\0')
	{
		ft_putstr_fd(argv[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(255);
	}
	if (!argv[2])
		exit((unsigned char)ft_atoi(argv[1]));
	else
		ft_putendl_fd("exit: too many arguments", 2);
	g_shell.result = 1;
}

void	ft_exit(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	if (i >= 2)
		exit_sup(argv);
	else if (i == 1)
	{
		ft_putendl_fd("exit", 2);
		exit(0);
	}
}

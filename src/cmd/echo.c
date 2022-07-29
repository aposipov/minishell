/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <lchristi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:00:10 by lchristi          #+#    #+#             */
/*   Updated: 2022/07/29 18:29:21 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	flag_n(char	**argv, int i)
{
	int	m;

	while (argv[i] && argv[i][0] == '-')
	{
		m = 1;
		while (argv[i][m] == 'n')
			m++;
		if (m != (int)ft_strlen(argv[i]))
			break ;
		i++;
	}
	return (i);
}

void	ft_echo(char **argv)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	if (argv[1] == NULL)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return ;
	}
	if (argv[i][0] == '-' && argv[i][1] == 'n')
		i = flag_n(argv, i);
	if (i > 1)
		k = 1;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		if (argv[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (k == 0)
		ft_putchar_fd('\n', STDOUT_FILENO);
	g_shell.result = 0;
}

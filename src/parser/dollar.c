/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:41:26 by lchristi          #+#    #+#             */
/*   Updated: 2022/07/29 18:41:34 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_env(char *str)
{
	char	**env;
	int		i;
	int		j;

	i = 0;
	j = (int)ft_strlen(str);
	env = g_shell.env;
	if (str[0] == '?')
	{
		tfree(str);
		return (ft_itoa(g_shell.result));
	}
	while (env && env[i])
	{
		if (ft_strncmp(env[i], str, j) == 0)
		{
			tfree(str);
			return (ft_strdup(env[i] + j));
		}
		i++;
	}
	tfree(str);
	return (ft_strdup(""));
}

char	*dollar(char *input, int *i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	int		j;

	j = ++(*i);
	while (input[*i] != '?' && ft_isdigit(input[*i]) != 1 \
		&& (ft_isalnum(input[j]) || input[j] == '_'))
		j++;
	if (j == *i && input[*i] != '?' && ft_isdigit(input[*i]) != 1)
		return (input);
	else if (input[*i] == '?' || ft_isdigit(input[*i]) == 1)
		j++;
	tmp = ft_substr(input, 0, (*i - 1));
	tmp2 = ft_substr(input, *i, (j - *i));
	tmp2 = ft_strjoin(tmp2, "=");
	tmp2 = find_env(tmp2);
	tmp3 = ft_strdup(input + j);
	tmp = mod_strjoin_gnl(tmp, tmp2);
	*i = (int)ft_strlen(tmp) - 1;
	tmp = mod_strjoin_gnl(tmp, tmp3);
	if (!tmp || !tmp2 || !tmp3)
		exit_error("Malloc error", -1);
	tfree3(input, tmp2, tmp3);
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:41:43 by lchristi          #+#    #+#             */
/*   Updated: 2022/07/29 18:42:11 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *add_eq(const char *tmp2)
{
	//char *str;
	char *str2;
	//int i =0;
	//int j =0;
	size_t num;
	num = ft_strlen(tmp2);
	printf("add_eq tmp2 = %s, len = %zu\n", tmp2, num);
	str2 = ft_strjoin(tmp2, "=");


	printf("add_eq = %s\n", str2);
	return (str2);
}

static char	*find_env(char *str)
{
	char	**env;
	int		i;
	int		j;

	printf("strin = %s\n", str); //

	i = 0;
	j = (int)ft_strlen(str);
	env = g_shell.env;
	if (str[0] == '?')
	{
		try_free(str);
		return (ft_itoa(g_shell.result));
	}
	while (env && env[i])
	{
		if (ft_strncmp(env[i], str, j) == 0)
		{
			try_free(str);
			return (ft_strdup(env[i] + j));
		}
		i++;
	}
	try_free(str);
	return (ft_strdup(""));
}

char	*dollar(char *input, int *i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	int		j;


	printf("input$ = %s\n", input); //

	j = ++(*i);
	while (input[*i] != '?' && ft_isdigit(input[*i]) != 1 \
		&& (ft_isalnum(input[j]) || input[j] == '_'))
		j++;
	if (j == *i && input[*i] != '?' && ft_isdigit(input[*i]) != 1)
		return (input);
	else if (input[*i] == '?' || ft_isdigit(input[*i]) == 1)
		j++;
	tmp = ft_substr(input, 0, (*i - 1));
	printf("tmp$ = %s\n", tmp);
	tmp2 = ft_substr(input, *i, (j - *i));
	printf("tmp2 substr = %s\n", tmp2);
	tmp2 = add_eq(tmp2);
	printf("tmp2 substr = %s\n", tmp2); //
	printf("length after sub = %zu\n", ft_strlen(tmp2));
//	tmp2[ft_strlen(tmp2)] = '='; //
//	tmp2[num] = '=';
	printf("length = %zu\n", ft_strlen(tmp2)); //
	printf("tmp2 strlen = %s\n", tmp2); //
	tmp2 = find_env(tmp2);
	printf("tmp2 find_env = %s\n", tmp2); //
	tmp3 = ft_strdup(input + j);
	tmp = ft_strjoin_gnl(tmp, tmp2);
	*i = (int)ft_strlen(tmp) - 1;
	tmp = ft_strjoin_gnl(tmp, tmp3);
	if (!tmp || !tmp2 || !tmp3)
		exit_error("Malloc error", -1);
	try_free3(input, tmp2, tmp3);
	printf(" out tmp$ = %s\n", tmp); //
	return (tmp);
}

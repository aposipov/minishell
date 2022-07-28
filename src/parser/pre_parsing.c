//
// Created by user on 07.07.22.
//

#include "minishell.h"

static int	lexer(const char *str, int *i)
{
	if (str[*i] == '|')
	{
		while (ft_isspace(str[++(*i)]))
			// ;
		if (str[*i] == '\0' || str[*i] == '|')
			return (-1);
	}
	if (str[*i] == '<' || str[*i] == '>')
	{
		(*i)++;
		if (str[*i] != str[*i - 1] && (str[*i] == '<' || str[*i] == '>'))
			return (-1);
		if (str[*i] == str[*i - 1])
			(*i)++;
		while (ft_isspace(str[*i]))
			(*i)++;
		if (str[*i] == '\0' || str[*i] == '|' || \
			str[*i] == '<' || str[*i] == '>')
			return (-1);
	}
	return (0);
}

static int	check_second_quote(char quote, char const *input, int *i)
{
	(*i)++;
	while (input[*i])
	{
		if (input[*i] == quote)
			return (*i);
		(*i)++;
	}
	return (-1);
}

static int	check_invalid(char const *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\"')
		{
			if (check_second_quote('\"', input, &i) == -1)
			{
				ft_putendl_fd("Syntax error expected second \"", 2);
				return (-1);
			}
		}
		if (input[i] == '\'')
		{
			if (check_second_quote('\'', input, &i) == -1)
			{
				ft_putendl_fd("Syntax error expected second \'", 2);
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

static int	check_begin(char const *input)
{
	int	i;

	i = 0;
	while (ft_isspace(input[i]))
		i++;
	if (input[i] == '\0')
		return (-1);
	if (input[i] == '|')
	{
		ft_putendl_fd("Syntax error near unexpected token `|'", 2);
		return (-1);
	}
	if (input[i] == ';')
	{
		ft_putendl_fd("Syntax error near unexpected token `;'", 2);
		return (-1);
	}
	i = check_invalid(input);
	return (i);
}

int	pre_parser(char const *line)
{
	int	i;

	i = 0;
	if (check_begin(line) == -1)
		return (-1);
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			check_second_quote(line[i], line, &i);
		if (lexer(line, &i) == -1)
		{
			ft_putendl_fd("Syntax error near unexpected token", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

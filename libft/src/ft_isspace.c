//
// Created by user on 07.07.22.
//

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
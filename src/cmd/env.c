//
// Created by user on 11.07.22.
//

#include "minishell.h"

static void	put_new_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->env == 1)
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

void	ft_env(char **argv)
{
	(void)argv;
	put_new_env(g_shell.new_env);
}

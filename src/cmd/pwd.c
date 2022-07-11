//
// Created by user on 11.07.22.
//

#include "minishell.h"

void	ft_pwd(char **argv)
{
	char	*pwd;
	char	*buf;
	t_env	*pwd_env;

	(void)argv;
	buf = NULL;
	pwd_env = find_list_env(g_shell.new_env, "PWD");
	if (pwd_env)
		pwd = pwd_env->value;
	else
		pwd = getcwd(buf, 0);
	if (!pwd)
	{
		ft_putendl_fd(strerror(errno), 2);
		g_shell.result = 1;
		return ;
	}
	ft_putendl_fd(pwd, STDOUT_FILENO);
}

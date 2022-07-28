//
// Created by user on 27.06.22.
//

#include "minishell.h"

t_shell  g_shell = {}; //

static int check_args(int  argc)
{
	if (argc != 1)
	{
		printf(RED"No input argements!\n"NC);
		return (1);
	}
	return (0);
}

//void	ctrl_c(int signal)
//{
//	if (signal == SIGINT)
//	{
//		ft_putchar_fd('\n', 2);
//		rl_replace_line("", 2);
//		rl_on_new_line();
//		rl_redisplay();
//		g_shell.result = signal - 1;
//	}
//}

static int	parsing(void)
{
	char	*input;

	//signal(SIGQUIT, SIG_IGN);
	//signal(SIGINT, &ctrl_c);
	init_signals();
	g_shell.signal = 0;
	input = readline(GREEN"minishell$ "NC);
	if (!input)
		return (-1);
	if (ft_strlen(input) == 0)
	{
		try_free(input);
		input = NULL;
		return (1);
	}
	add_history(input);
	if (pre_parser(input) != -1)
		parser(input);
	else
		return (1);
	try_free(input);
	return (0);
}

static void	init_shell(int argc, char **argv, char **env)
{
	t_command	*new;
	t_list		*new_list;

	(void)argc;
	(void)argv;
	g_shell.env = NULL;
	if (env && env[0] != NULL)
		g_shell.new_env = init_env(env);
	else
		g_shell.new_env = NULL;
	start_pwd(g_shell.new_env);
	edit_shlvl(g_shell.new_env);
	g_shell.result = 0;
	g_shell.fd_1 = tdup(1);
	g_shell.fd_0 = tdup(0);
	new = command_new();
	new_list = ft_lstnew((void *)new);
	if (new_list == NULL)
		exit_error("Error malloc\n", -1);
	ft_lstadd_back(&g_shell.cmd, (void *)new_list);
}



int	main(int argc, char **argv, char **env)
{
	int	status;

	//rl_outstream = stderr; //WHY?
	if(check_args(argc))
		exit(1);
	init_shell(argc, argv, env);
	while (1)
	{
		status = parsing();
		if (status == 1)
			continue ;
		if (status == -1)
		{
			ft_putendl_fd("exit", 2);
			exit (0);
		}
		if (g_shell.signal == 0)
		{
			if (ft_lstsize(g_shell.cmd) > 1)
				pipes(ft_lstsize(g_shell.cmd));
			else
				tparent();
			tdup2(g_shell.fd_1, 1);
			tdup2(g_shell.fd_0, 0);
		}
		cleaning();
	}
}
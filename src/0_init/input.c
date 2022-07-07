//
// Created by user on 05.07.22.
//
#include "minishell.h"

int	get_input()
{
	char	*input;
	//int		status;

	//status = 0;
	input = readline("minishell-v2.0$ ");
	if (!input)
	{
		write (1, "exit\n", 5);
		//clear_exit(0);
	}
	add_history(input);
	//*tokens = tokenizer(input);
	free(input);
	//status = syntax_analyser(*tokens);
//	if (status != 0)
//	{
//		set_status(status);
//		return (status);
//	}
	return (0);
}

int check_env(char const *line)
{
	char *str = "env";
	int i = 0;

	if (line[i] == ' ')
		printf ("is space\n");
	if (line[i] == '\t')
		printf ("is tab\n");
	while (line[i] != '\0')
	{
		if (line[i] == str[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void loop(char **env)
{
	char *line;
	int i = 0;
	(void)env;

	while(1)
	{
		//get_input();
		line = readline(GREEN"minishell$ "NC);
		if (check_env(line))
		{
			while(env[i])
			{
				printf("%s\n", env[i]);
				i++;
			}
		}

		printf(GREEN"minishell$ "NC);
		printf("%s\n", line);
		free(line);
	}
	//return 0;

}


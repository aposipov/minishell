//
// Created by user on 27.06.22.
//

#include "minishell.h"

int check_env(char const *line)
{
	char *str = "env";
	int i = 0;

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

	while(1)
	{
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
		printf("%s\n",line);
		free(line);
	}
	//return 0;

}

int check_mshell(int  argc)
{
	if (argc != 1)
		printf(RED"No input argements!\n"NC);
	return (0);
}

int main(int argc, char **argv, char **env)
{
	(void)argv; //
	(void)env;  //
	check_mshell(argc);
	loop(env);
//	char *line;
//	line = getenv("PATH");
//	printf("%s\n", line);
	return (0);
}
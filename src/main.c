//
// Created by user on 27.06.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "my_colours.h"
#include <readline/readline.h>
//#include <readline/history.h>


int main(int argc, char **argv, char **env)
{
	char *line;
	int i = 0;
	//signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	printf("argc = %d\n", argc);
	printf("argv = %s\n", argv[1]);
	while(env[i])
	{
		printf("env = %s\n", env[i]);
		i++;
	}
	while(1)
	{
//		signal(SIGINT, SIG_IGN);
		line = readline(GREEN"minishell$ "NC);
		printf(GREEN"minishell$ "NC);
		printf("%s\n",line);
		free(line);
	}
	printf("%s\n", getenv(argv[1]));
	return 0;
}
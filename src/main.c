//
// Created by user on 27.06.22.
//

#include "minishell.h"

int check_mshell(int  argc)
{
	if (argc != 1)
	{
		printf(RED"No input argements!\n"NC);
		return (1);
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
	(void)argv; //
	(void)env;  //
	if (check_mshell(argc))
		return (1);
	init_signals();
	loop(env);
//	char *line;
//	line = getenv("PATH");
//	printf("%s\n", line);
	return (0);
}
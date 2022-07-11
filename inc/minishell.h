//
// Created by user on 04.07.22.
//

#ifndef MINISHELL_H
# define MINISHELL_H

# include "my_colours.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef struct s_command
{
	t_list	*argv;
	t_list	*redirect;
}				t_command;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				env;
	int				exp;
	struct s_env	*next;
}				t_env;

typedef struct s_shell
{
	char	**env;
	t_env	*new_env;
	t_list	*cmd;
	int		fd_1;
	int		fd_0;
	int		result;
	int		signal;
}				t_shell;

t_shell g_shell;

int 	loop(char **env);
int		pre_parser(char const *line);
void	parser(char const *input);
void	init_signals(void);
char	*double_redirect_handler(char const *input, int *i, int
*this_is_redirect);
void	pipe_handler(int *i);
char	*other_handler(char const *input, int *i);
char	*limiter_handler(char *rd, char *limiter);


#endif

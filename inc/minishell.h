//
// Created by user on 04.07.22.
//

#ifndef MINISHELL_H
# define MINISHELL_H

# include "my_colours.h"
# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

//# include <dirent.h>
//# include <sys/types.h>

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

typedef struct s_pipex
{
	t_list	*cmd;
	int		c_pipe;
	int		iter;
	int		flag;
}			t_pipex;

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


/*utils*/
void	try_free(void *target);
void	try_free3(void *a, void *b, void *c);
char	**free_2d_arr(char **arr);
void	exit_error(char *str, int code);
void	cleaning(void);
t_command *command_new(void);
char **set_command_struct(t_list *lst_cmd);
void	status_handler(void);
int	try_dup(int fd);
int	try_dup2(int fd, int fd2);
void	err_msg(char *str);
void	sup_dup(int *fd);
char	*ft_strjoin_gnl(char *s1, char *s2); // peredelat

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:12:03 by lchristi          #+#    #+#             */
/*   Updated: 2022/07/29 18:12:25 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <dirent.h>
# include <sys/types.h>

typedef struct s_command
{
	t_list	*argv;
	t_list	*redirect;
}				t_command;

typedef struct s_env // int exp
{
	char			*key;
	char			*value;
	int				env;
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

extern t_shell	g_shell;

int			pre_parser(char const *line);
void		parser(char const *input);
void		init_signals(void);
char		*double_redirect_handler(char const *input, int *i, int \
*this_is_redirect);
void		pipe_handler(int *i);
char		*other_handler(char const *input, int *i);
char		*limiter_handler(char *rd, char *limiter);
char		*clear_quotes(char *input);
char		*dollar(char *input, int *i);
void		tparent(void);
/*utils*/
void		tfree(void *target);
void		tfree3(void *a, void *b, void *c);
char		**free_2d_arr(char **arr);
void		exit_error(char *str, int code);
void		cleaning(void);
t_command	*command_new(void);
char		**set_command_struct(t_list *lst_cmd);
void		status_handler(void);
int			tdup(int fd);
int			tdup2(int fd, int fd2);
void		err_msg(char *str);
void		sup_dup(int *fd);
char		*mod_strjoin_gnl(char *s1, char *s2);
/* builtins */
void		ft_pwd(char **argv);
void		ft_echo(char **argv);
void		ft_cd(char **argv);
void		ft_unset(char **argv);
void		ft_export(char **argv);
void		ft_env(char **argv);
void		ft_exit(char **argv);
/* env */
t_env		*init_env(char **env);
t_env		*new_env(char *str, int env); // int exp
void		add_back_env(t_env **env, t_env *new);
void		logic_export(int *flags, int i, t_env *env, char *arg);
t_env		*find_list_env(t_env *env, char *str);
void		edit_shlvl(t_env *env);
void		start_pwd(t_env *env);
void		export_get_value(char *arg, int i, char **value, int f_plus);
void		edit_env_line(t_env *env, char *find, char *edit);
char		**env_arr(t_env *env, int export);
/* exec */
void		executing(t_list *lst_cmd);
int			builtins(char **cmd);
/* pipes */
void		pipes(int argc);
pid_t		*init_pipes(int argc, t_pipex *pipex, int *a, int *b);
void		closer_pipes(int *a, int *b);

#endif

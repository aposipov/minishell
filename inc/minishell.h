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
# include <readline/readline.h>
# include <readline/history.h>

int	get_input();
void loop(char **env);



void	init_signals(void);

#endif

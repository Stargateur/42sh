/*
** my_shell.h for my_shell in /home/plasko_a/programation/epitech/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 22:09:47 2014 Antoine Plaskowski
** Last update Sun May 18 22:17:19 2014 Antoine Plaskowski
*/

#ifndef		MY_SHELL_H_
# define	MY_SHELL_H_

# include	"my_env.h"

typedef	struct	s_shell	t_shell;

struct		s_shell
{
  t_env		*env;
  int		exit_value;
  char		exit;
};

int		my_shell(t_shell *shell, char **env_tab);

#endif		/* !MY_SHELL_H_ */

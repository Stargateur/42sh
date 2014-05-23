/*
** my_unsetenv.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 22 15:57:43 2014 Pierrick Gicquelais
** Last update Fri May 23 11:00:04 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_env.h"
#include	"my_str.h"

int		my_unsetenv(t_shell *shell, t_fd *fd, char **argv)
{
  int		i;

  (void)fd;
  i = 1;
  while (argv[i])
    shell->env = my_sup_env(shell->env, argv[i++]);
  return (0);
}

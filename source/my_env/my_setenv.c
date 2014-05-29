/*
** my_setenv.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 22 15:36:41 2014 Pierrick Gicquelais
** Last update Thu May 29 14:37:57 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_env.h"
#include	"my_str.h"

int		my_setenv(t_shell *shell, t_fd *fd, char **argv)
{
  int		len;

  (void)fd;
  len = my_len_tab(argv);
  if (len == 1)
    return (0);
  else if (argv[1] && is_alpha(argv[1]))
    {
      my_putstr("Varible name must contain alphanumeric characters\n", 1);
      return (1);
    }
  else if (len == 2)
    shell->env = my_add_env(shell->env, argv[1], "");
  else if (len == 3)
    shell->env = my_add_env(shell->env, argv[1], argv[2]);
  else
    {
      my_putstr("setenv: Too many arguments.\n", 1);
      return (1);
    }
  return (0);
}

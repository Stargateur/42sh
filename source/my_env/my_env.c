/*
** my_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 22 14:42:17 2014 Pierrick Gicquelais
** Last update Sat May 24 12:54:36 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_env.h"
#include	"my_str.h"

static int	check_option(t_shell *shell, char **argv, int *i)
{
  if (argv[*i] && my_strcmp(argv[*i], "-i") == 0)
    my_putstr("Env not implemented !\n", 1);
  else if (argv[*i] && my_strcmp(argv[*i], "-u") == 0)
    {
      if (!argv[*i + 1])
	{
	  my_putstr("env: option requires an argument -- 'u'\n", 1);
	  return (1);
	}
      (*i)++;
      shell->env = my_sup_env(shell->env, argv[*i]);
    }
  else
    {
      my_putstr("env: invalid option -- ", 1);
      my_putstr(argv[*i], 1);
      my_putchar('\n', 1);
      return (1);
    }
  (*i)++;
  return (0);
}

int		my_env(t_shell *shell, t_fd *fd, char **argv)
{
  int		len;
  int		i;

  if (shell == NULL || fd == NULL || argv == NULL)
    return (1);
  i = 1;
  len = my_len_tab(argv);
  if (len == 1)
    {
      if (fd->fd_1 != -1)
	my_aff_all_env(shell->env, fd->fd_1);
      else
	my_aff_all_env(shell->env, 1);
    }
  else
    while (argv[i])
      if (check_option(shell, argv, &i))
	return (1);
  return (0);
}

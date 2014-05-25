/*
** echo.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_echo
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 23 16:48:04 2014 Pierrick Gicquelais
** Last update Sun May 25 21:16:56 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_echo.h"
#include	"my_str.h"

void		get_opt(char *str, t_echo *opt)
{
  int		i;

  i = 0;
  while (str[++i])
    {
      if (str[i] == 'n')
	opt->t_n = 1;
      else if (str[i] == 'e')
	opt->t_e = 1;
      else if (str[i] == 'E')
	opt->t_e = 0;
    }
}

int		my_echo(t_shell *shell, t_fd *fd, char **argv)
{
  t_echo	opt;

  if (shell == NULL || fd == NULL || argv == NULL)
    return (1);
  if (my_len_tab(argv) <= 1)
    {
      if (fd->fd_1 != -1)
	my_putchar('\n', fd->fd_1);
      else
	my_putchar('\n', 1);
      return (0);
    }
  opt.t_n = 0;
  opt.t_e = 0;
  opt.start = 0;
  my_check_echo(argv, &opt);
  if (fd->fd_1 != -1)
    norm_echo(argv, &opt, fd->fd_1);
  else
    norm_echo(argv, &opt, 1);
  return (0);
}

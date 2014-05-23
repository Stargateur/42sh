/*
** echo.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_echo
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 23 16:48:04 2014 Pierrick Gicquelais
** Last update Fri May 23 17:31:18 2014 Pierrick Gicquelais
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
  t_echo	*opt;

  (void)shell;
  (void)fd;
  if ((opt = malloc(sizeof(t_echo))) == NULL)
    return (1);
  opt->t_n = 0;
  opt->t_e = 0;
  opt->start = 0;
  my_check_echo(argv, opt);
  norm_echo(argv, opt);
  free(opt);
  return (0);
}

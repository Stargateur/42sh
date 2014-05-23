/*
** check.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_echo
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 23 16:50:32 2014 Pierrick Gicquelais
** Last update Fri May 23 16:51:11 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_echo.h"
#include	"my_str.h"

int		my_get_flag(char *str, t_echo *opt, int x)
{
  int		i;

  if (str == NULL)
    return (FAIL);
  i = 0;
  while (str[++i])
    {
      if (str[i] != 'n' && str[i] != 'e' && str[i] != 'E')
	{
	  opt->start = x;
	  return (FAIL);
	}
    }
  get_opt(str, opt);
  return (OK);
}

int		my_check_echo(char **tab, t_echo *opt)
{
  int		i;

  if (tab[0] == NULL)
    return (FAIL);
  i = 0;
  while (tab[++i] && tab[i][0] == '-')
    {
      if (my_get_flag(tab[i], opt, i) == FAIL)
	return (FAIL);
    }
  opt->start = i;
  return (OK);
}

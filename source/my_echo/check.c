/*
** check.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_echo
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 23 16:50:32 2014 Pierrick Gicquelais
** Last update Sun May 25 21:34:29 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_echo.h"
#include	"my_str.h"

int		my_get_flag(char *str, t_echo *opt, int x)
{
  opt->start = x;
  if (str == NULL || str[0] == '\0' || str[1] == '\0')
    return (FAIL);
  if (str[1] != 'n' && str[1] != 'e' && str[1] != 'E')
    return (FAIL);
  if (str[2] != '\0')
    return (FAIL);
  get_opt(str, opt);
  return (OK);
}

int		my_check_echo(char **tab, t_echo *opt)
{
  int		i;

  if (tab[0] == NULL)
    return (FAIL);
  i = 1;
  while (tab[i] && tab[i][0] == '-')
    {
      if (my_get_flag(tab[i], opt, i) == FAIL)
	return (FAIL);
      i++;
    }
  opt->start = i;
  return (OK);
}

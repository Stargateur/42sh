/*
** check.c for check in /home/marsil_g/Documents/PSU/42sh
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Sun May 18 13:37:27 2014 Gabriele Marsili
** Last update Mon May 19 00:20:52 2014 Gabriele Marsili
*/

#include	<stdlib.h>
#include	"includes.h"

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

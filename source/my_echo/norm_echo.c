/*
** norm_echo.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_echo
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 23 16:49:44 2014 Pierrick Gicquelais
** Last update Sat May 24 12:53:07 2014 Antoine Plaskowski
*/

#include	<stdio.h>
#include	"my_echo.h"
#include	"my_str.h"

int		norm_echo(char **tab, t_echo *opt, int fd)
{
  int		k;

  k = opt->start - 1;
  if (opt->t_e == 1)
    {
      check_slash(tab, opt);
      return (OK);
    }
  else
    {
      while (tab[++k] != NULL)
	{
	  my_putstr(tab[k], fd);
	  my_putchar(' ', fd);
	}
    }
  if (opt->t_n == 0)
    my_putchar('\n', fd);
  return (0);
}

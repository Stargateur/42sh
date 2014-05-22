/*
** norm_echo.c for echo norm in /home/marsil_g/Documents/PSU/42sh
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Fri May 16 14:52:12 2014 Gabriele Marsili
** Last update Thu May 22 16:21:37 2014 Gabriele Marsili
*/

#include	<stdio.h>
#include	"includes.h"
#include	"my_str.h"

int		norm_echo(char **tab, t_echo *opt)
{
  int		k;

  k = opt->start - 1;
  while (tab[++k] != NULL)
    {
      if (opt->t_e == 1)
	{
	  check_slash(tab, opt);
	  return (OK);
	}
      else
	my_putstr(tab[k], 1);
      my_putchar(' ', 1);
    }
  if (opt->t_n == 0)
    my_putchar('\n', 1);
  return (0);
}

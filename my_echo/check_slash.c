/*
** check_slash.c for check slash in /home/marsil_g/rendu/PSU_2013_42sh/my_echo
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Mon May 19 10:24:28 2014 Gabriele Marsili
** Last update Thu May 22 16:21:51 2014 Gabriele Marsili
*/

#include	<stdlib.h>
#include	"includes.h"
#include	"my_str.h"

void		my_get_escape(char *tab)
{
  char		*str;

  str = "abcefnrtv";
  if (my_char_in_str(tab[1], str) == -1)
    my_putstr(tab, 1);
  else
    my_putchar(tab, 1);
}

void		check_slash(char **tab, t_echo *opt)
{
  int		k;

  k = opt->start - 1;
  while (tab[++k] != NULL)
    {
      if (tab[k][0] == '\\' && tab[k][2] == 0)
	my_get_escape(tab[k]);
      else
	my_putstr(tab[k], 1);
      my_putchar('\n', 1);
    }
  if (opt->t_n == 0)
    my_putchar('\n', 1);
}

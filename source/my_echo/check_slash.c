/*
** check_slash.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_echo
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 23 16:50:08 2014 Pierrick Gicquelais
** Last update Sat May 24 14:05:58 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_echo.h"
#include	"my_str.h"

int		print_escape(int x, t_echo *opt)
{
  if (x == 1)
    my_putchar('\a', 1);
  else if (x == 1)
    my_putchar('\b', 1);
  else if (x == 2)
    return (FAIL);
  else if (x == 3)
    my_putchar(' ', 1);
  else if (x == 4)
    my_putchar('\f', 1);
  else if (x == 5)
    {
      if (opt->t_n == 0)
	my_putchar('\n', 1);
    }
  else if (x == 6)
    my_putchar('\r', 1);
  else if (x == 7)
    my_putchar('\t', 1);
  else if (x == 8)
    my_putchar('\v', 1);
  return (1);
}

int		print_echo(char *tab, t_echo *opt)
{
  char		*str;
  int		i;
  int		x;

  i = -1;
  str = "abcefnrtv";
  while (tab[++i])
    {
      if (tab[i] == '\\' && tab[i++])
	{
	  x = my_char_in_str(tab[i++], str);
	  if (x == -1)
	    my_putchar(tab[i -1], 1);
	  else
	    if (print_escape(x, opt) == FAIL)
	      return (FAIL);
	  i--;
	}
      else
      	my_putchar(tab[i], 1);
    }
  return (OK);
}

int		check_slash(char **tab, t_echo *opt)
{
  int		k;

  k = opt->start - 1;
  while (tab[++k] != NULL)
    {
      if (print_echo(tab[k], opt) == FAIL)
	{
	  if (opt->t_n == 0)
	    my_putchar('\n', 1);
	  return (FAIL);
	}
      my_putchar(' ', 1);
    }
  if (opt->t_n == 0)
    my_putchar('\n', 1);
  return (OK);
}

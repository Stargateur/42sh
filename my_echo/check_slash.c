/*
** check_slash.c for check slash in /home/marsil_g/rendu/PSU_2013_42sh/my_echo
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Mon May 19 10:24:28 2014 Gabriele Marsili
** Last update Thu May 22 20:21:46 2014 Gabriele Marsili
*/

#include	<stdlib.h>
#include	"includes.h"
#include	"my_str.h"

int		print_escape(int x)
{
  if (x == 1)
    my_putchar('\a', 1);
  else if (x == 1)
    my_putchar('\b', 1);
  else if (x == 2)
    return (FAIL);
  else if (x == 3)
    my_putchar('\e', 1);
  else if (x == 4)
    my_putchar('\f', 1);
  else if (x == 5)
    my_putchar('\n', 1);
  else if (x == 6)
    my_putchar('\r', 1);
  else if (x == 7)
    my_putchar('\t', 1);
  else if (x == 8)
    my_putchar('\v', 1);
  return (1);
}

int		print_echo(char *tab)
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
	    my_putchar(tab[++i], 1);
	  else
	    {
	      if (print_escape(x) == FAIL)
		return (FAIL);
	      i--;
	    }
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
      if (print_echo(tab[k]) == FAIL)
	return (FAIL);
      my_putchar(' ', 1);
    }
  if (opt->t_n == 0)
    my_putchar('\n', 1);
  return (OK);
}

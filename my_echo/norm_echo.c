/*
** norm_echo.c for echo norm in /home/marsil_g/Documents/PSU/42sh
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Fri May 16 14:52:12 2014 Gabriele Marsili
** Last update Mon May 19 00:23:44 2014 Gabriele Marsili
*/

#include	<stdio.h>
#include	"includes.h"

void		norm_echo(char **tab, t_echo *opt)
{
  int		k;

  k = opt->start - 1;
  while (tab[++k] != NULL)
    my_fputstr(1, my_strcat(tab[k], " "));
  if (opt->t_n == 0)
    my_fputchar(1, '\n');
}

/*
** main.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Mon Mar 24 14:31:46 2014 Pierrick Gicquelais
** Last update Thu Apr  3 23:04:19 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<signal.h>
#include	"my_str.h"
#include	"my_get_next_line.h"

int		main()
{
  char		*s;

  my_putstr("Bienvenue dans le 42Sh mes loulous <3.\n", 1);
  my_putstr("42sh$> ", 1);
  signal(SIGINT, SIG_IGN);
  while ((s = my_get_next_line(0)) != NULL)
    {
      my_putstr(s, 1);
      my_putstr("\n42sh$> ", 1);
      free(s);
    }
  free(s);
  return (0);
}

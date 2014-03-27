/*
** main.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Mon Mar 24 14:31:46 2014 Pierrick Gicquelais
** Last update Thu Mar 27 14:56:05 2014 Pierrick Gicquelais
*/

#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"shell.h"

void		putstr(char *s)
{
  while (*s)
    {
      write(1, &(*s), 1);
      s++;
    }
}

int		main()
{
  char		*s;

  printf("Bienvenue dans le 42Sh mes loulous <3.\n");
  putstr("42sh$> ");
  signal(SIGINT, SIG_IGN);
  while ((s = get_next_line(0)) != NULL)
    {
      puts(s);
      putstr("42sh$> ");
      free(s);
    }
  return (0);
}

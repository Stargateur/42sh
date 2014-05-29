/*
** term_init.c for term_init in /home/costa_b/rendu/42sh/PSU_2013_42sh/source/my_edit
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu May 29 13:43:51 2014 Kevin Costa
** Last update Thu May 29 13:50:50 2014 Kevin Costa
*/

#include	<term.h>
#include	<curse.h>
#include	<stdlib.h>
#include	"my_env.h"

int		term_init(t_env *env)
{
  char		*term;

  if ((term = my_found_env("TERM", env)) == NULL ||
      tgetent(NULL, term) < 1)
    tgetent(NULL, "xterm");
}

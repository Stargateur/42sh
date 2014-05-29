/*
** term_init.c for term_init in /home/costa_b/rendu/42sh/PSU_2013_42sh/source/my_edit
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu May 29 13:43:51 2014 Kevin Costa
** Last update Thu May 29 14:37:15 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_env.h"
#include	"my_termcaps.h"

int		term_init(t_env *env)
{
  t_env		*term;

  if ((term = my_found_env(env, "TERM")) == NULL)
    return (1);
  if (my_tgetent(env->value))
    return (1);
  return (0);
}

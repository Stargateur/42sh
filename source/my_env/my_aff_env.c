/*
** my_aff_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:27:01 2014 Pierrick Gicquelais
** Last update Fri May 30 09:34:56 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_env.h"
#include	"my_str.h"

int		my_aff_env(t_env *env, const int fd)
{
  if (env != NULL)
    {
      my_putstr(env->name, fd);
      my_putchar('=', fd);
      my_putstr(env->value, fd);
      my_putchar('\n', fd);
    }
  return (0);
}

int		my_aff_all_env(t_env *env, const int fd)
{
  env = my_first_env(env);
  while (env != NULL)
    {
      my_aff_env(env, fd);
      env = env->next;
    }
  return (0);
}

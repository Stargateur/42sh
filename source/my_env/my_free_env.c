/*
** my_free_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:13:13 2014 Pierrick Gicquelais
** Last update Tue May 13 20:28:21 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_env.h"

void		my_free_env(t_env *env)
{
  if (env != NULL)
    {
      free(env->name);
      free(env);
    }
}

void		my_free_all_env(t_env *env)
{
  t_env		*tmp;

  env = my_first_env(env);
  while (env != NULL)
    {
      tmp = env;
      env = env->next;
      my_free_env(tmp);
    }
}

/*
** my_put_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:16:21 2014 Pierrick Gicquelais
** Last update Sun May 25 12:46:43 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_env.h"

t_env		*my_put_env(t_env *old, t_env *env)
{
  if (env == NULL)
    return (NULL);
  if ((old = my_last_env(old)) != NULL)
    old->next = env;
  env->prev = old;
  env->next = NULL;
  return (env);
}

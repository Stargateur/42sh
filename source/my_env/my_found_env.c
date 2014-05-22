/*
** my_found_env.c for my_found_env in /home/gicque_p/rendu/PSU_2013_42sh
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 22 14:06:06 2014 Pierrick Gicquelais
** Last update Thu May 22 14:14:37 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_env.h"
#include	"my_str.h"

t_env		*my_found_env(t_env *env, char *name)
{
  env = my_first_env(env);
  while (env != NULL)
    {
      if (my_strcmp(env->name, name) == 0)
	return (env);
      env = env->next;
    }
  return (NULL);
}

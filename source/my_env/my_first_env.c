/*
** my_first_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:14:49 2014 Pierrick Gicquelais
** Last update Mon May 12 10:15:26 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_env.h"

t_env		*my_first_env(t_env *env)
{
  if (env != NULL)
    while (env->prev != NULL)
      env = env->prev;
  return (env);
}

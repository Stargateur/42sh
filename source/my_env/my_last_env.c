/*
** my_last_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:15:37 2014 Pierrick Gicquelais
** Last update Mon May 12 10:16:10 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_env.h"

t_env		*my_last_env(t_env *env)
{
  if (env != NULL)
    while (env->next != NULL)
      env = env->next;
  return (env);
}

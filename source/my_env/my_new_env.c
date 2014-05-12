/*
** my_new_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:11:23 2014 Pierrick Gicquelais
** Last update Mon May 12 10:12:48 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_env.h"
#include	"my_str.h"

t_env		*my_new_env(void)
{
  t_env		*env;

  if ((env = my_malloc(sizeof(t_env))) == NULL)
    return (NULL);
  env->prev = NULL;
  env->next = NULL;
  env->name = NULL;
  return (env);
}

/*
** my_new_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:11:23 2014 Pierrick Gicquelais
** Last update Sun May 18 22:24:23 2014 Antoine Plaskowski
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
  env->value = NULL;
  return (env);
}

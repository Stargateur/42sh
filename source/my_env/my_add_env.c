/*
** my_add_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 22 13:04:39 2014 Pierrick Gicquelais
** Last update Thu May 29 14:25:09 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_env.h"
#include	"my_str.h"

t_env		*my_add_env(t_env *env, char *name, char *value)
{
  t_env		*tmp;

  if (is_alpha(value))
    {
      my_putstr("Variable name must contain alphanumeric characters\n", 1);
      return (my_first_env(env));
    }
  else if ((tmp = my_found_env(env, name)) != NULL)
    {
      if (tmp->value != NULL)
	free(tmp->value);
      tmp->value = my_strdup(value);
    }
  else
    env = my_append_env(env, my_strdup(name), my_strdup(value));
  return (my_first_env(env));
}

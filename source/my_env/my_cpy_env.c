/*
** my_cpy_env.c for my_cpy_env in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_env
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 25 12:40:44 2014 Antoine Plaskowski
** Last update Sun May 25 12:47:10 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_env.h"
#include	"my_str.h"

t_env		*my_cpy_env(t_env *env)
{
  t_env		*cpy;

  cpy = NULL;
  env = my_first_env(env);
  while (env != NULL)
    {
      if ((cpy = my_put_env(cpy, my_new_env())) == NULL)
	return (NULL);
      cpy->value = my_strdup(env->value);
      cpy->name = my_strdup(env->name);
      env = env->next;
    }
  return (my_first_env(cpy));
}

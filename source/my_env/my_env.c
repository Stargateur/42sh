/*
** my_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:23:43 2014 Pierrick Gicquelais
** Last update Mon May 12 10:42:31 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_env.h"

t_env		*my_env(char **envp)
{
  t_env		*env;
  int		i;

  i = 0;
  if (envp == NULL)
    return (NULL);
  env = NULL;
  while (envp[i])
    {
      env = my_append_env(env, envp[i]);
      i++;
    }
  return (env);
}

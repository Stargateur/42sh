/*
** my_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:23:43 2014 Pierrick Gicquelais
** Last update Sun May 18 22:31:14 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_env.h"
#include	"my_str.h"

static char	*my_name(char *env)
{
  t_uint	i;

  i = 0;
  while (env[i] != '=' && env[i] != '\0')
    i++;
  return (my_strndup(env, i));
}

static char	*my_value(char *env)
{
  while (*env != '=' && *env != '\0')
    env++;
  return (my_strdup(env));
}

t_env		*my_env(char **env_tab)
{
  t_env		*env;

  env = NULL;
  if (env_tab != NULL)
    while (*env_tab != NULL)
      {
	if ((env = my_append_env(env, my_name(*env_tab), my_value(*env_tab))) == NULL)
	  return (NULL);
	env_tab++;
      }
  return (my_first_env(env));
}

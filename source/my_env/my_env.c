/*
** my_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:23:43 2014 Pierrick Gicquelais
** Last update Tue May 13 20:25:25 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_env.h"
#include	"my_str.h"

t_env		*my_env(char **envp)
{
  t_env		*env;

  env = NULL;
  if (envp != NULL)
    while (*envp != NULL)
      {
	env = my_append_env(env, my_strdup(*envp++));
      }
  return (my_first_env(env));
}

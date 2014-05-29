/*
** my_put_ps1.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_shell
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 16:15:04 2014 Pierrick Gicquelais
** Last update Thu May 29 17:58:36 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_shell.h"

t_env		*my_put_ps1(t_env *env)
{
  t_env		*tmp;
  char		*ps1;
  char		*ps2;

  tmp = my_found_env(env, "USER");
  if (tmp != NULL)
    {
      ps1 = my_strcat("[", tmp->value);
      ps2 = my_strcat(ps1, "]$> ");
      free(ps1);
      env = my_add_env(env, "PS1", ps2);
      free(ps2);
    }
  return (env);
}

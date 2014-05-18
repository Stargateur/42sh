/*
** my_len_env.c for my_len_env in /home/plasko_a/programation/epitech/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 22:40:27 2014 Antoine Plaskowski
** Last update Sun May 18 22:43:19 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_env.h"

t_uint		my_len_env(t_env *env)
{
  t_uint	i;

  env = my_first_env(env);
  i = 0;
  while (env != NULL)
    {
      i++;
      env = env->next;
    }
  return (i);
}

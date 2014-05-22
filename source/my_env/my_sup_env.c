/*
** my_sup_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 22 13:10:10 2014 Pierrick Gicquelais
** Last update Thu May 22 14:35:09 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_env.h"
#include	"my_str.h"

t_env		*my_sup_env(t_env *env, char *name)
{
  t_env		*tmp;

  if ((tmp = my_found_env(env, name)) != NULL)
    {
      if (tmp->next != NULL)
	{
	  env = tmp->next;
	  tmp->next->prev = tmp->prev;
	}
      if (tmp->prev != NULL)
	{
	  env = tmp->prev;
	  tmp->prev->next = tmp->next;
	}
      my_free_env(tmp);
    }
  return (my_first_env(env));
}

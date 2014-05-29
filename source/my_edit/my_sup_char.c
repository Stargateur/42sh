/*
** my_sup_char.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_edit
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 18:55:47 2014 Pierrick Gicquelais
** Last update Thu May 29 20:06:10 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_edit.h"

t_edit		*my_sup_char(t_edit *edit)
{
  t_edit	*tmp;

  tmp = edit;
  if (tmp != NULL)
    {
      if (tmp->next != NULL)
	{
	  edit = tmp->next;
	  tmp->next->prev = tmp->prev;
	}
      if (tmp->prev != NULL)
	{
	  edit = tmp->prev;
	  tmp->prev->next = tmp->next;
	}
      my_free_char(tmp);
    }
  return (edit);
}

/*
** my_sup_char.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_edit
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 18:55:47 2014 Pierrick Gicquelais
** Last update Thu May 29 23:58:26 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_edit.h"

t_edit		*my_sup_char(t_edit *edit)
{
  t_edit	*ret;

  ret = NULL;
  if (edit != NULL)
    {
      if (edit->next != NULL)
	{
	  ret = edit->next;
	  edit->next->prev = edit->prev;
	}
      if (edit->prev != NULL)
	{
	  ret = edit->prev;
	  edit->prev->next = edit->next;
	}
      my_free_char(edit);
    }
  return (ret);
}

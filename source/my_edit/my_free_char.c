/*
** my_free_char.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_edit
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 18:54:11 2014 Pierrick Gicquelais
** Last update Thu May 29 22:00:21 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_edit.h"

void		my_free_char(t_edit *edit)
{
  if (edit != NULL)
    free(edit);
}

void		my_free_all_char(t_edit *edit)
{
  t_edit	*tmp;

  edit = my_first_char(edit);
  while (edit != NULL)
    {
      tmp = edit;
      edit = edit->next;
      my_free_char(tmp);
    }
}

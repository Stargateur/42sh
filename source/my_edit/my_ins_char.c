/*
** my_ins_char.c for my_ins_char in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_edit
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu May 29 22:00:56 2014 Antoine Plaskowski
** Last update Thu May 29 23:35:31 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_edit.h"

t_edit		*my_ins_char(t_edit *edit, t_edit *ins)
{
  if (edit != NULL && ins != NULL)
    {
      if (edit->next != NULL)
	edit->next->prev = ins;
      ins->prev = edit;
      ins->next = edit->next;
      edit->next = ins;
    }
  return (ins);
}

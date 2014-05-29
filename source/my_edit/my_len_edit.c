/*
** my_len_edit.c for my_len_edit in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_edit
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu May 29 22:18:50 2014 Antoine Plaskowski
** Last update Thu May 29 22:22:01 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_edit.h"

t_uint		my_len_edit(t_edit *edit)
{
  t_uint	i;

  i = 0;
  edit = my_first_char(edit);
  while (edit != NULL)
    {
      i++;
      edit = edit->next;
    }
  return (i);
}

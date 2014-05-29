/*
** my_first_char.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_edit
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 18:49:29 2014 Pierrick Gicquelais
** Last update Thu May 29 18:50:34 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_edit.h"

t_edit		*my_first_char(t_edit *edit)
{
  if (edit != NULL)
    while (edit->prev != NULL)
      edit = edit->prev;
  return (edit);
}

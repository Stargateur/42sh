/*
** my_last_char.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_edit
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 18:50:40 2014 Pierrick Gicquelais
** Last update Thu May 29 18:51:11 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_edit.h"

t_edit		*my_last_char(t_edit *edit)
{
  if (edit != NULL)
    while (edit->next != NULL)
      edit = edit->next;
  return (edit);
}

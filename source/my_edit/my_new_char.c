/*
** my_new_char.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_edit
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 18:47:10 2014 Pierrick Gicquelais
** Last update Thu May 29 19:02:40 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_edit.h"
#include	"my_str.h"

t_edit		*my_new_char(void)
{
  t_edit	*edit;

  if ((edit = my_malloc(sizeof(t_edit))) == NULL)
    return (NULL);
  edit->prev = NULL;
  edit->next = NULL;
  edit->c = 0;
  return (edit);
}

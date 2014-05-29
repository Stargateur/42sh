/*
** my_aff_char.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_edit
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 18:52:46 2014 Pierrick Gicquelais
** Last update Thu May 29 18:54:01 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_edit.h"
#include	"my_str.h"

void		my_aff_char(t_edit *edit)
{
  if (edit != NULL)
    my_putchar(edit->c, 1);
}

void		my_aff_all_char(t_edit *edit)
{
  t_edit	*tmp;

  tmp = my_first_char(edit);
  while (tmp)
    {
      my_aff_char(tmp);
      tmp = tmp->next;
    }
}

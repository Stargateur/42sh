/*
** my_aff_char.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_edit
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 18:52:46 2014 Pierrick Gicquelais
** Last update Thu May 29 23:01:01 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_edit.h"
#include	"my_str.h"

int		my_aff_char(t_edit *edit, const int fd)
{
  if (edit != NULL)
    my_putchar(edit->c, fd);
  return (0);
}

int		my_aff_all_char(t_edit *edit, const int fd)
{
  edit = my_first_char(edit);
  while (edit != NULL)
    {
      my_aff_char(edit, fd);
      edit = edit->next;
    }
  return (0);
}

int		my_aff_max_char(t_edit *edit, int max, const int fd)
{
  int		i;

  i = 0;
  edit = my_first_char(edit);
  while (edit != NULL && i < max)
    {
      my_aff_char(edit, fd);
      i++;
      edit = edit->next;
    }
  return (0);
}

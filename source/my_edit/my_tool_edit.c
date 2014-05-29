/*
** my_tool_edit.c for my_tool_edit in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_edit
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu May 29 23:49:25 2014 Antoine Plaskowski
** Last update Fri May 30 00:08:54 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_edit.h"
#include	"my_str.h"
#include	"my_termcaps.h"

t_edit		*my_ins(t_edit *edit, t_uint i, char c)
{
  t_uint	j;
  t_edit	*new;

  j = 0;
  edit = my_first_char(edit);
  while (edit != NULL && ++j < i)
    edit = edit->next;
  if ((new = my_new_char()) == NULL)
    return (NULL);
  new->c = c;
  return (my_ins_char(edit, new));
}

t_edit		*my_del(t_edit *edit, t_uint i)
{
  t_uint	j;

  j = 0;
  edit = my_first_char(edit);
  while (edit != NULL && ++j < i)
    edit = edit->next;
  return (my_sup_char(edit));
}

int		my_aff(t_edit *edit, t_uint max)
{
  char		*str;

  str = my_tgetstr("rc");
  tputs(str, 0, &my_putint);
  str = my_tgetstr("cd");
  tputs(str, 0, &my_putint);
  my_aff_max_char(edit, max, 0);
  return (0);
}

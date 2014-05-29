/*
** my_edit_to_str.c for my_edit_to_str in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_edit
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu May 29 22:18:39 2014 Antoine Plaskowski
** Last update Thu May 29 22:32:23 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_edit.h"
#include	"my_str.h"

char		*my_edit_to_str(t_edit *edit)
{
  char		*str;
  t_uint	i;

  edit = my_first_char(edit);
  if ((str = my_malloc(sizeof(char) * (my_len_edit(edit) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (edit != NULL)
    {
      str[i++] = edit->c;
      edit = edit->next;
    }
  str[i] = '\0';
  return (str);
}

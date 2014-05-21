/*
** my_node_editor.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_editor
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 20 17:03:57 2014 Pierrick Gicquelais
** Last update Tue May 20 17:04:57 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_editor.h"

t_edit		*my_first_char(t_edit *editor)
{
  if (editor != NULL)
    while (editor->prev != NULL)
      editor = editor->prev;
  return (editor);
}

t_edit		*my_last_char(t_edit *editor)
{
  if (editor != NULL)
    while (editor->next != NULL)
      editor = editor->next;
  return (editor);
}

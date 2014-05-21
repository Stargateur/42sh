/*
** my_new_editor.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_editor
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 20 17:02:38 2014 Pierrick Gicquelais
** Last update Tue May 20 17:03:49 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_editor.h"

t_edit		*my_new_editor(void)
{
  t_edit	*editor;

  if ((editor = malloc(sizeof(t_edit))) == NULL)
    return (NULL);
  editor->prev = NULL;
  editor->next = NULL;
  editor->c = 0;
  return (editor);
}

/*
** my_free_editor.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_editor
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 20 17:09:29 2014 Pierrick Gicquelais
** Last update Tue May 20 17:10:17 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_editor.h"

void		my_free_editor(t_edit *editor)
{
  t_edit	*tmp;

  editor = my_first_char(editor);
  while (editor)
    {
      tmp = editor;
      editor = editor->next;
      free(tmp);
    }
}

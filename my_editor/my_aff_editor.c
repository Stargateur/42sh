/*
** my_aff_editor.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_editor
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 20 17:08:25 2014 Pierrick Gicquelais
** Last update Tue May 20 17:09:19 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_editor.h"

void		my_aff_editor(t_edit *editor)
{
  editor = my_first_char(editor);
  while (editor)
    {
      write(1, &editor->c, 1);
      editor = editor->next;
    }
}

/*
** main.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_editor
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 20 17:10:41 2014 Pierrick Gicquelais
** Last update Wed May 21 16:39:30 2014 Pierrick Gicquelais
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		"my_editor.h"

t_edit			*get_char(t_edit *editor)
{
  char			buf[4];

  while (read(0, buf, 3) > 0)
    {
      if (!is_printable(buf[0]))
      	{
      	  tputs(tgetstr("me", NULL), 1, my_putchar);
      	  editor = my_append_char(editor, buf[0]);
      	  my_putchar(buf[0]);
      	}
      if (!is_enter(buf[0]))
      	return (editor);
      else if (!is_delete(buf[0]))
      	tputs(tgetstr("dc", NULL), 1, my_putchar);
      else if (!is_left(buf))
      	{
      	  if (editor && editor->prev)
	    {
	      my_putchar('\b');
	      //	      tputs(tgetstr("LE", NULL), 1, my_putchar);
	      editor = editor->prev;
	    }
      	}
      else if (!is_right(buf))
      	{
      	  if (editor && editor->next)
	    {
	      tputs(tgetstr("nd", NULL), 1, my_putchar);
	      editor = editor->next;
	    }
      	}
    }
  return (NULL);
}

void			get_string(void)
{
  t_edit		*editor;

  while (42)
    {
      editor = NULL;
      write(1, "Editor> ", 8);
      editor = get_char(editor);
      my_aff_editor(editor);
      my_free_editor(editor);
    }
}

int			main()
{
  struct termios	t;

  if (tgetent(NULL, "xterm") == -1)
    return (1);
  if (tcgetattr(0, &t) == -1)
    return (1);
  if (raw_attr(&t))
    return (1);
  get_string();
  if (canon_attr(&t))
    return (1);
  return (0);
}

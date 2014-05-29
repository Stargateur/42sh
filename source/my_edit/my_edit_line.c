/*
** my_edit_line.c for my_edit_line in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_edit
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Thu May 29 21:57:27 2014 Antoine Plaskowski
** Last update Fri May 30 00:07:23 2014 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_termcaps.h"
#include	"my_edit.h"
#include	"my_str.h"

static int	my_read_buf(char *buf)
{
  int		i;

  i = 0;
  while (i < 3)
    buf[i++] = 0;
  return (read(0, buf, 3));
}

static int	my_move(t_edit *edit, char *buf, t_uint *i)
{
  if (buf[2] == 68 && *i != 0)
    (*i)--;
  else if (buf[2] == 67 && *i < my_len_edit(edit))
    (*i)++;
  else
    return (1);
  return (0);
}

static t_edit	*my_read_line(void)
{
  t_edit	*edit;
  char		buf[3];
  t_uint	i;

  edit = NULL;
  i = 0;
  while (my_read_buf(buf))
    {
      /* my_putnbr(buf[0], 1); */
      /* my_putstr(" ", 1); */
      /* my_putnbr(buf[1], 1); */
      /* my_putstr(" ", 1); */
      /* my_putnbr(buf[2], 1); */
      /* my_putstr("\n", 1); */
      if (buf[0] >= ' ' && buf[0] <= '~')
	edit = my_ins(edit, i++, buf[0]);
      else if (buf[0] == 4 || buf[0] == '\n')
	{
	  if (buf[0] == '\n')
	    edit = my_append_char(edit, buf[0]);
	  my_aff(edit, my_len_edit(edit));
	  return (edit);
	}
      else if (buf[0] == 127 && i != 0)
	edit = my_del(edit, i--);
      else if (buf[0] == 27 && buf[1] == 91)
	my_move(edit, buf, &i);
      my_aff(edit, i);
    }
  return (edit);
}

char		*my_edit_line(void)
{
  t_edit	*edit;
  t_ter		t;
  t_ter		save;
  char		*str;

  my_tcgetattr(&t);
  my_tcgetattr(&save);
  my_raw_mode(&t);
  my_echo_off(&t);
  str = my_tgetstr("sc");
  tputs(str, 0, &my_putint);
  if ((edit = my_read_line()) == NULL)
    return (NULL);
  str = my_edit_to_str(edit);
  my_free_all_char(edit);
  my_reset(&save);
  return (str);
}

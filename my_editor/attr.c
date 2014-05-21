/*
** attr.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_editor
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 21 07:53:10 2014 Pierrick Gicquelais
** Last update Wed May 21 08:19:29 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_editor.h"

int		canon_attr(struct termios *t)
{
  t->c_lflag |= ICANON;
  t->c_lflag |= ECHO;
  if (tcsetattr(0, TCSANOW, t) == -1)
    return (1);
  return (0);
}

int		raw_attr(struct termios *t)
{
  t->c_lflag &= ~ICANON;
  t->c_lflag &= ~ECHO;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, t) == -1)
    return (1);
  return (0);
}

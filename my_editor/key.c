/*
** key.c for  in /home/gicque_p/rendu/PSU_2013_42sh/my_editor
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 21 07:57:16 2014 Pierrick Gicquelais
** Last update Wed May 21 08:24:18 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_editor.h"

int		is_printable(char c)
{
  if ((c >= 32 && c <= 126) || c == 10)
    return (0);
  return (1);
}

int		is_enter(char c)
{
  if (c == 10)
    return (0);
  return (1);
}

int		is_delete(char c)
{
  if (c == 127)
    return (0);
  return (1);
}

int		is_left(char *s)
{
  if (s[0] == 27 && s[1] == 91 && s[2] == 68)
    return (0);
  return (1);
}

int		is_right(char *s)
{
  if (s[0] == 27 && s[1] == 91 && s[2] == 68)
    return (0);
  return (1);
}

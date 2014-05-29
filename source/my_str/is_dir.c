/*
** is_dir.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_str
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 14:41:25 2014 Pierrick Gicquelais
** Last update Thu May 29 14:42:02 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"

int		is_dir(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    {
      if (s[i] == '/')
	return (0);
      i++;
    }
  return (1);
}

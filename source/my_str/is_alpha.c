/*
** is_alpha.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_str
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 14:21:15 2014 Pierrick Gicquelais
** Last update Thu May 29 18:32:42 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"

int		is_alpha(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    {
      if (!((s[i] >= '0' && s[i] <= '9') || \
	    (s[i] >= 'a' && s[i] <= 'z') || \
	    (s[i] >= 'A' && s[i] <= 'Z') ||
	    (s[i] == '_')))
	return (1);
      i++;
    }
  return (0);
}

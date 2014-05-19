/*
** my_strlcpy.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 19 17:47:28 2014 Pierrick Gicquelais
** Last update Mon May 19 17:56:03 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_strlcpy(char *dest, char *src, char delim, int start)
{
  int		i;

  i = start;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (src[i] && src[i] != delim)
    {
      dest[i - start] = src[i];
      i++;
    }
  dest[i - start] = '\0';
  return (0);
}


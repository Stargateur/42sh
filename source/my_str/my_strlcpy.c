/*
** my_strlcpy.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_str
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 28 19:25:26 2014 Pierrick Gicquelais
** Last update Wed May 28 19:28:01 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_strlcpy(char *dest, char *src, char delim, int start)
{
  int		i;

  i = start;
  if (dest == NULL || src == NULL)
    exit(EXIT_FAILURE);
  while (src[i] && src[i] != delim)
    {
      dest[i - start] = src[i];
      i++;
    }
  dest[i - start] = '\0';
  return (0);
}


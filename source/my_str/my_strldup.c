/*
** my_strldup.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_str
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 28 19:25:09 2014 Pierrick Gicquelais
** Last update Wed May 28 19:28:18 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"

char		*my_strldup(char *str, char delim, int start)
{
  char		*cpy;

  if (str == NULL)
    exit(EXIT_FAILURE);
  if ((cpy = malloc(((my_strlen(str) + 1) - start) * sizeof(char))) == NULL)
    exit(EXIT_FAILURE);
  if (my_strlcpy(cpy, str, delim, start))
    {
      free(cpy);
      exit(EXIT_FAILURE);
    }
  return (cpy);
}

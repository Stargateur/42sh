/*
** my_strldup.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 19 17:45:23 2014 Pierrick Gicquelais
** Last update Mon May 19 18:01:05 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"

char		*my_strldup(char *str, char delim, int start)
{
  char		*cpy;

  if (str == NULL)
    return (NULL);
  if ((cpy = malloc(((my_strlen(str) + 1) - start) * sizeof(char))) == NULL)
    return (NULL);
  if (my_strlcpy(cpy, str, delim, start))
    {
      free(cpy);
      return (NULL);
    }
  return (cpy);
}

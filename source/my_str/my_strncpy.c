/*
** my_strncpy.c for my_strncpy in /home/plasko_a/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct  7 09:49:46 2013 Antoine Plaskowski
** Last update Fri Apr 18 03:46:27 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_typedef.h"

int		my_strncpy(char *dest, char *src, t_uint n)
{
  t_uint	i;

  if (dest == NULL || src == NULL)
    return (1);
  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (0);
}

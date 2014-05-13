/*
** my_malloc.c for my_malloc in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Nov 29 17:01:00 2013 Antoine Plaskowski
** Last update Sat May 10 21:19:49 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_typedef.h"
#include	"my_str.h"

void		*my_malloc(t_uint size_octect)
{
  void		*pt;

  if (size_octect == 0)
    {
      my_putstr("Warning malloc of 0\n", 2);
      exit(1);
    }
  if ((pt = malloc(size_octect)) == NULL)
    {
      my_putstr("Insufficient memory\n", 2);
      exit(1);
    }
  return (pt);
}

void		*my_calloc(t_uint size_octect)
{
  void		*pt;
  char		*tmp;
  t_uint	i;

  if (size_octect == 0)
    {
      my_putstr("Warning malloc of 0\n", 2);
      exit(1);
    }
  if ((pt = malloc(size_octect)) == NULL)
    {
      my_putstr("Insufficient memory\n", 2);
      exit(1);
    }
  tmp = pt;
  i = 0;
  while (i < size_octect)
    tmp[i++] = 0;
  return (pt);
}

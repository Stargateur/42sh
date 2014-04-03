/*
** my_malloc.c for my_malloc in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Nov 29 17:01:00 2013 Antoine Plaskowski
** Last update Fri Mar 21 09:27:48 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

void		*my_malloc(int nbr_octet)
{
  void		*pt;

  if (nbr_octet == 0)
    {
      my_putstr("Warning malloc of 0\n", 2);
      exit(1);
    }
  if ((pt = malloc(nbr_octet)) == NULL)
    {
      my_putstr("Insufficient memory\n", 2);
      exit(1);
    }
  return (pt);
}

void		*my_calloc(int nbr_octet)
{
  void		*pt;
  char		*tmp;
  int		i;

  if (nbr_octet == 0)
    {
      my_putstr("Warning calloc of 0\n", 2);
      exit(1);
    }
  if ((pt = malloc(nbr_octet)) == NULL)
    {
      my_putstr("Insufficient memory\n", 2);
      exit(1);
    }
  tmp = pt;
  i = 0;
  while (i < nbr_octet)
    tmp[i++] = 0;
  return (pt);
}

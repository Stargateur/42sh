/*
** my_getnbr_base.c for my_getnbr_base in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Nov 27 14:55:31 2013 Antoine Plaskowski
** Last update Fri May  2 03:30:05 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_typedef.h"

int		my_getnbr_base(const char *str, const char *base)
{
  int		signe;
  int		nbr;
  int		unite;
  t_uint	len;

  if (str == NULL || base == NULL || (len = my_strlen(base)) < 2)
    return (0);
  signe = 1;
  while (*str == '-' || *str == '+')
    if (*str++ == '-')
      signe *= -1;
  while (*str == base[0] && *str != '\0')
    str++;
  nbr = 0;
  if (signe == 1)
    while ((unite = my_char_in_str(*str++, base)) != -1)
      nbr = nbr * len + unite;
  else
    while ((unite = my_char_in_str(*str++, base)) != -1)
      nbr = nbr * len - unite;
  return (nbr);
}

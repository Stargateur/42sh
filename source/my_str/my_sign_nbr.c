/*
** my_sign_nbr.c for my_sign_nbr in /home/plasko_a/rendu/prog_elem/sources/my_parsing
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Apr 24 22:12:48 2014 Antoine Plaskowski
** Last update Thu Apr 24 22:14:06 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_sign_nbr(const char *str)
{
  int		sign;

  if (str == NULL)
    return (0);
  sign = 1;
  while (*str == '-' || *str == '+')
    if (*str++ == '-')
      sign *= -1;
  return (sign);
}

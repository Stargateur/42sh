/*
** my_is_num.c for my_is_num in /home/plasko_a/rendu/prog_elem/sources/my_parsing
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Apr 24 22:07:11 2014 Antoine Plaskowski
** Last update Fri Apr 25 00:28:47 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_is_num(const char *str)
{
  if (str == NULL)
    return (1);
  while (*str == '-' || *str == '+')
    str++;
  if (*str < '0' && *str > '9')
    return (1);
  while (*str >= '0' && *str <= '9')
    str++;
  if (*str != '\0')
    return (1);
  return (0);
}

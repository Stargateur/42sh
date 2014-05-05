/*
** my_strlen.c for my_strlen in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 10:50:55 2013 Antoine Plaskowski
** Last update Thu May  1 20:03:28 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_typedef.h"

t_uint		my_strlen(const char *str)
{
  const char	*tmp;

  tmp = str;
  if (str != NULL)
    while (*str != '\0')
      str++;
  return (str - tmp);
}

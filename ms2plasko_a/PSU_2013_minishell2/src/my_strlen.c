/*
** my_strlen.c for my_strlen in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 10:50:55 2013 Antoine Plaskowski
** Last update Sat Dec 14 23:02:40 2013 Antoine Plaskowski
*/

#include	<stdlib.h>

size_t		my_strlen(const char *str)
{
  size_t	result;

  if (str == NULL)
    return (0);
  result = 0;
  while (*str++ != '\0')
    result++;
  return (result);
}

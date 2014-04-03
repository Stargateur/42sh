/*
** my_strlen.c for my_strlen in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 10:50:55 2013 Antoine Plaskowski
** Last update Mon Mar 24 20:14:46 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_strlen(const char *str)
{
  int	result;

  if (str == NULL)
    return (0);
  result = 0;
  while (*str++ != '\0')
    result++;
  return (result);
}

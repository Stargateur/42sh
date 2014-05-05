/*
** my_strcmp.c for my_strcmp in /home/plasko_a/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct  7 14:55:18 2013 Antoine Plaskowski
** Last update Sun May  4 21:37:06 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_typedef.h"

int		my_strcmp(const char *s1, const char *s2)
{
  t_uint	i;

  if (s1 == NULL || s2 == NULL)
    return (-1);
  i = 0;
  while (s1[i] != '\0' && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}

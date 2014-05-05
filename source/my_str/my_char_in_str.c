/*
** my_char_in_str.c for my_char_in_str in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Nov 15 05:46:34 2013 Antoine Plaskowski
** Last update Fri May  2 03:15:48 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_char_in_str(const char c, const char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      {
	if (str[i] == c)
	  return (i);
	i++;
      }
  return (-1);
}

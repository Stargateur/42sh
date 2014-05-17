/*
** my_str.c for my_str in /home/plasko_a/rendu/PSU_2013_minitalk
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Feb 25 19:06:12 2014 Antoine Plaskowski
** Last update Sat May 17 02:33:31 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_aff_str(t_str *str, const int fd)
{
  if (str != NULL)
    {
      my_putstr(str->str, fd);
      my_putchar('\n', fd);
    }
  return (0);
}

int		my_aff_all_str(t_str *str, const int fd)
{
  str = my_first_str(str);
  while (str != NULL)
    {
      my_aff_str(str, fd);
      str = str->next;
    }
  return (0);
}

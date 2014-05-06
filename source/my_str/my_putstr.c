/*
** my_putstr.c for my_putstr in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 10:36:52 2013 Antoine Plaskowski
** Last update Tue May  6 16:59:01 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_str.h"

int		my_putstr(const char *str, const int fd)
{
  t_uint	len;

  if (str == NULL)
    return (1);
  len = my_strlen(str);
  return (write(fd, str, len) != len);
}

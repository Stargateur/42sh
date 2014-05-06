/*
** my_putchar.c for putchar in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct 21 10:46:02 2013 Antoine Plaskowski
** Last update Tue May  6 16:57:59 2014 Pierrick Gicquelais
*/

#include	<unistd.h>
#include	"my_str.h"

int		my_putchar(const char c, const int fd)
{
  return (write(fd, &c, 1) != 1);
}

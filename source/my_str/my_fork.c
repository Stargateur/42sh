/*
** my_fork.c for my_fork in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May  6 13:19:37 2014 Antoine Plaskowski
** Last update Wed May 14 07:12:04 2014 Antoine Plaskowski
*/

#include	<unistd.h>
#include	"my_str.h"

int		vfork(void);

int		my_fork(void)
{
  int		id;

  if ((id = vfork()) == -1)
    my_putstr("Can't fork\n", 2);
  return (id);
}

/*
** my_dup2.c for my_dup2 in /home/plasko_a/programation/epitech/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May 14 01:00:06 2014 Antoine Plaskowski
** Last update Wed May 14 01:33:29 2014 Antoine Plaskowski
*/

#include	<unistd.h>
#include	"my_str.h"

int		my_dup2(int src, int dest)
{
  int		fd;

  if ((fd = dup2(src, dest)) != dest)
    my_putstr("can't dup2\n", 2);
  /* close(src); */
  return (fd);
}

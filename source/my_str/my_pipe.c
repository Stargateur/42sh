/*
** my_pipe.c for my_pipe in /home/plasko_a/programation/epitech/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 23:22:48 2014 Antoine Plaskowski
** Last update Tue May 13 23:24:51 2014 Antoine Plaskowski
*/

#include	<unistd.h>
#include	"my_str.h"

int		my_pipe(int *fd_pipe)
{
  if (pipe(fd_pipe))
    {
      my_putstr("can't create a pipe\n", 2);
      return (-1);
    }
  return (0);
}

/*
** my_init_fd.c for my_init_fd in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 03:55:12 2014 Antoine Plaskowski
** Last update Sun May 25 16:37:15 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_exec.h"

int		my_init_fd(t_fd *fd)
{
  if (fd == NULL)
    return (1);
  fd->dleft = NULL;
  fd->str = NULL;
  fd->fd_0 = -1;
  fd->fd_1 = -1;
  fd->fd_pipe[0] = -1;
  fd->fd_pipe[1] = -1;
  fd->fd_redir[0] = -1;
  fd->fd_redir[1] = -1;
  return (0);
}


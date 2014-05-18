/*
** my_close_fd.c for my_close_fd in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 03:54:14 2014 Antoine Plaskowski
** Last update Sun May 18 05:40:35 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_exec.h"

int		my_close_fd(t_fd *fd)
{
  if (fd == NULL)
    return (1);
  if (fd->fd_0 != -1)
    close(fd->fd_0);
  if (fd->fd_1 != -1)
    close(fd->fd_1);
  if (fd->fd_redir[0] != -1)
    close(fd->fd_redir[0]);
  if (fd->fd_redir[1] != -1)
    close(fd->fd_redir[1]);
  if (fd->fd_pipe[0] != -1)
    close(fd->fd_pipe[0]);
  if (fd->fd_pipe[1] != -1)
    close(fd->fd_pipe[1]);
  return (0);
}


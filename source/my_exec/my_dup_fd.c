/*
** my_dup_fd.c for my_dup_fd in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 03:48:06 2014 Antoine Plaskowski
** Last update Thu May 29 16:49:46 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_exec.h"
#include	"my_str.h"

int		my_dup_fd(t_fd *fd)
{
  if (fd == NULL)
    return (1);
  if (fd->fd_0 != -1)
    my_dup2(fd->fd_0, 0);
  if (fd->fd_1 != -1)
    my_dup2(fd->fd_1, 1);
  if (fd->fd_redir[0] != -1)
    my_dup2(fd->fd_redir[0], 0);
  if (fd->fd_pipe[0] != -1)
    my_dup2(fd->fd_pipe[0], 0);
  if (fd->fd_pipe[1] != -1)
    my_dup2(fd->fd_pipe[1], 1);
  return (0);
}


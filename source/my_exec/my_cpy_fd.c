/*
** my_cpy_fd.c for my_cpy_fd in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu May 29 16:58:35 2014 Antoine Plaskowski
** Last update Thu May 29 17:09:14 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_shell.h"

int		my_cpy_fd(t_fd *dest, t_fd *src)
{
  if (src == NULL || dest == NULL)
    return (1);
  dest->fd_0 = src->fd_0;
  dest->fd_1 = src->fd_1;
  dest->fd_pipe[0] = src->fd_pipe[0];
  dest->fd_pipe[1] = src->fd_pipe[1];
  dest->fd_redir[0] = src->fd_redir[0];
  dest->fd_redir[1] = src->fd_redir[1];
  return (0);
}

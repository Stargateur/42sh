/*
** my_exec_pipe.c for my_exec_pipe in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Sat May 24 14:19:33 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_shell.h"
#include	"my_exec.h"
#include	"my_str.h"

static int	my_son(t_btree *btree, t_shell *shell, t_fd *fd)
{
  int		builtin;

  if (fd->fd_redir[1] != -1)
    {
      close(fd->fd_redir[1]);
      fd->fd_redir[1] = -1;
    }
  if ((builtin = my_check_builtin(btree->token)) != -1)
    return (my_builtin(shell, btree->token, fd));
  return (my_execve(btree, fd, shell));
}

static int      my_father(t_btree *btree, t_fd *fd)
{
  int           tmp;

  if (fd->fd_redir[1] != -1)
    my_redir_dleft_in_father(btree->token, fd);
  tmp = fd->fd_pipe[0];
  fd->fd_pipe[0] = -1;
  my_close_fd(fd);
  my_init_fd(fd);
  fd->fd_pipe[0] = tmp;
  return (0);
}

static int	my_exec_pipe_fork(t_btree *btree, t_fd *fd, t_shell *shell)
{
  int		fd_pipe[2];
  int		pid;

  if (btree == NULL || fd == NULL)
    return (1);
  if (my_pipe(fd_pipe))
    return (1);
  fd->fd_pipe[1] = fd_pipe[1];
  my_redirection(btree->token, fd);
  if ((pid = fork()) == 0)
    return (my_son(btree, shell, fd));
  else if (pid == -1)
    return (my_put_error("can't fork ...\n"));
  close(fd->fd_pipe[0]);
  fd->fd_pipe[0] = fd_pipe[0];
  return (my_father(btree, fd));
}

static int	my_recur_pipe(t_btree *btree, t_fd *fd, t_shell *shell)
{
  if (btree == NULL || fd == NULL)
    return (1);
  if (btree->token->type == O_PIPE)
    {
      if (my_exec_pipe_fork(btree->left, fd, shell))
	return (1);
      return (my_recur_pipe(btree->right, fd, shell));
    }
  return (my_exec_pipe_last(btree, fd, shell));
}

int		my_exec_pipe(t_btree *btree, t_shell *shell)
{
  t_fd		fd;

  if (btree == NULL || btree->token == NULL || btree->token->type != O_PIPE)
    return (1);
  my_init_fd(&fd);
  if (my_exec_pipe_first(btree->left, &fd, shell))
    return (1);
  return (my_recur_pipe(btree->right, &fd, shell));
}

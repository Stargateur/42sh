/*
** my_exec_pipe.c for my_exec_pipe in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Sun May 18 05:44:28 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include        <sys/wait.h>
#include	"my_exec.h"
#include	"my_str.h"

static int	my_son(t_btree *btree, char **env, t_fd *fd)
{
  if (fd->fd_redir[1] != -1)
    {
      close(fd->fd_redir[1]);
      fd->fd_redir[1] = -1;
    }
  return (my_execve(btree, fd, env));
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

static int	my_exec_pipe_fork(t_btree *btree, t_fd *fd, char **env)
{
  int		pid;
  int		fd_pipe[2];

  if (btree == NULL || fd == NULL)
    return (1);
  if (my_pipe(fd_pipe))
    return (1);
  fd->fd_pipe[1] = fd_pipe[1];
  my_redirection(btree->token, fd);
  if ((pid = fork()) == 0)
    return (my_son(btree, env, fd));
  else if (pid == -1)
    return (my_put_error("can't fork ...\n"));
  close(fd->fd_pipe[0]);
  fd->fd_pipe[0] = fd_pipe[0];
  return (my_father(btree, fd));
}

static int	my_recur_pipe(t_btree *btree, t_fd *fd, char **env)
{
  if (btree == NULL || fd == NULL)
    return (1);
  if (btree->token->type == O_PIPE)
    {
      if (my_exec_pipe_fork(btree->left, fd, env))
	return (1);
      return (my_recur_pipe(btree->right, fd, env));
    }
  return (my_exec_pipe_last(btree, fd, env));
}

int		my_exec_pipe(t_btree *btree, char **env)
{
  t_fd		fd;

  if (btree == NULL || btree->token == NULL || btree->token->type != O_PIPE)
    return (1);
  my_init_fd(&fd);
  my_exec_pipe_first(btree->left, &fd, env);
  return (my_recur_pipe(btree->right, &fd, env));
}

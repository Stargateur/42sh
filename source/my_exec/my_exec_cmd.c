/*
** my_exec_cmd.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 12:46:13 2014 Pierrick Gicquelais
** Last update Sat May 17 19:47:13 2014 Antoine Plaskowski
*/

#define		_BSD_SOURCE

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

static int	my_init_fd(t_fd *fd)
{
  fd->fd_0 = -1;
  fd->fd_1 = -1;
  fd->fd_pipe[0] = -1;
  fd->fd_pipe[1] = -1;
  return (0);
}

static int	my_close_fd(t_fd *fd)
{
  if (fd->fd_0 != -1)
    close(fd->fd_0);
  if (fd->fd_1 != -1)
    close(fd->fd_1);
  if (fd->fd_pipe[0] != -1)
    close(fd->fd_pipe[0]);
  if (fd->fd_pipe[1] != -1)
    close(fd->fd_pipe[1]);
  return (0);
}

int		my_exec_cmd(t_btree *btree, char **env)
{
  t_fd		fd;
  int		pid;
  int		ret;

  if (btree == NULL)
    return (1);
  my_init_fd(&fd);
  my_redirection(btree->token, &fd);
  if ((pid = vfork()) == 0)
    return (my_execve(btree, &fd, env));
  else if (pid == -1)
    return (my_put_error("can't vfork... \n"));
  if (fd.fd_pipe[1] != -1)
    my_redir_dleft_in_father(btree->token, &fd);
  my_close_fd(&fd);
  waitpid(pid, &ret, WUNTRACED);
  return (WEXITSTATUS(ret));
}

/*
** my_exec_pipe_last.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 12:46:13 2014 Pierrick Gicquelais
** Last update Sun May 18 22:58:42 2014 Antoine Plaskowski
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_shell.h"
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

static int	my_son(t_btree *btree, t_fd *fd, t_shell *shell)
{
  if (fd->fd_redir[1] != -1)
    {
      close(fd->fd_redir[1]);
      fd->fd_redir[1] = -1;
    }
  return (my_execve(btree, fd, shell));
}

static int	my_father(t_btree *btree, t_fd *fd, int pid)
{
  int		ret;

  if (fd->fd_redir[1] != -1)
    my_redir_dleft_in_father(btree->token, fd);
  my_close_fd(fd);
  waitpid(pid, &ret, WUNTRACED);
  return (WEXITSTATUS(ret));
}

int		my_exec_pipe_last(t_btree *btree, t_fd *fd, t_shell *shell)
{
  int		pid;

  if (btree == NULL || fd == NULL)
    return (1);
  my_redirection(btree->token, fd);
  if ((pid = fork()) == 0)
    return (my_son(btree, fd, shell));
  else if (pid == -1)
    return (my_put_error("can't fork... \n"));
  return (my_father(btree, fd, pid));
}

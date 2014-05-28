/*
** my_exec_pipe_first.c for my_exec_pipe_first in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 03:45:08 2014 Antoine Plaskowski
** Last update Tue May 27 17:31:13 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_shell.h"
#include	"my_exec.h"
#include	"my_str.h"

static int	my_son(t_btree *btree, t_fd *fd, t_shell *shell)
{
  int		builtin;

  if ((builtin = my_check_builtin(btree->token)) != -1)
    exit (my_builtin(shell, btree->token, fd));
  if (fd->fd_redir[1] != -1)
    {
      my_free_all_str(fd->str);
      close(fd->fd_redir[1]);
      fd->fd_redir[1] = -1;
    }
  close(fd->fd_pipe[0]);
  fd->fd_pipe[0] = -1;
  return (my_execve(btree, fd, shell));
}

static int	my_father(t_shell *shell, t_btree *btree, t_fd *fd, int pid)
{
  int		tmp;

  if (fd->fd_redir[1] != -1)
    my_aff_redir_dleft(fd);
  tmp = fd->fd_pipe[0];
  fd->fd_pipe[0] = -1;
  my_close_fd(fd);
  my_init_fd(fd);
  fd->fd_pipe[0] = tmp;
  if (shell != NULL)
    shell->pid = my_append_pid(NULL, pid);
  if (my_found_token(btree->token, O_ESPE) != NULL && shell->pid != NULL)
    shell->pid->wait = 0;
  return (0);
}

int		my_exec_pipe_first(t_btree *btree, t_fd *fd, t_shell *shell)
{
  int		pid;

  if (btree == NULL || fd == NULL)
    return (1);
  if (my_pipe(fd->fd_pipe))
    return (1);
  my_redirection(btree->token, fd);
  if (fd->fd_redir[1] != -1)
    my_redir_dleft_in_father(btree->token, fd);
  if ((pid = fork()) == 0)
    return (my_son(btree, fd, shell));
  else if (pid == -1)
    return (my_put_error("can't fork ...\n"));
  return (my_father(shell, btree, fd, pid));
}

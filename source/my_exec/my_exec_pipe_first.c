/*
** my_exec_pipe_first.c for my_exec_pipe_first in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 03:45:08 2014 Antoine Plaskowski
** Last update Thu May 29 18:17:32 2014 Antoine Plaskowski
*/

#define		_BSD_SOURCE
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_shell.h"
#include	"my_exec.h"
#include	"my_str.h"

static void	my_son(t_btree *btree, t_fd *fd, t_shell *shell)
{
  t_fd		cpy;

  my_cpy_fd(&cpy, fd);
  if (cpy.fd_redir[1] != -1)
    close(cpy.fd_redir[1]);
  if (cpy.fd_pipe[0] != -1)
    close(fd->fd_pipe[0]);
  cpy.fd_redir[1] = -1;
  cpy.fd_pipe[0] = -1;
  my_execve(btree, &cpy, shell);
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
  if (shell->cd != NULL)
    {
      my_chdir(shell->cd);
      free(shell->cd);
      shell->cd = NULL;
    }
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
  if ((pid = vfork()) == 0)
    my_son(btree, fd, shell);
  else if (pid == -1)
    return (my_put_error("can't fork ...\n"));
  return (my_father(shell, btree, fd, pid));
}

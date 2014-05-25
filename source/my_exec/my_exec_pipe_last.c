/*
** my_exec_pipe_last.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 12:46:13 2014 Pierrick Gicquelais
** Last update Sun May 25 15:37:57 2014 Antoine Plaskowski
*/

#define		_POSIX_SOURCE
#include	<stdlib.h>
#include	<signal.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
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

static int	my_father(t_btree *btree, t_fd *fd, int pid, t_shell *shell)
{
  int		ret;

  if (fd->fd_redir[1] != -1)
    my_redir_dleft_in_father(btree->token, fd);
  my_close_fd(fd);
  my_wait_pid(shell->pid);
  if (my_found_token(btree->token, O_ESPE) != NULL)
    return (0);
  if (waitpid(pid, &ret, WUNTRACED) != pid)
    my_putstr("waitpid error\n", 2);
  if (WIFEXITED(ret))
    return (WEXITSTATUS(ret));
  if (WIFSIGNALED(ret))
    my_aff_signal(WTERMSIG(ret));
  if (WIFSTOPPED(ret))
    {
      my_putstr("no job control we kill your prog\n", 2);
      kill(pid, SIGKILL);
    }
  return (1);
}

int		my_exec_pipe_last(t_btree *btree, t_fd *fd, t_shell *shell)
{
  int		builtin;
  int		pid;

  if (btree == NULL || fd == NULL)
    return (1);
  my_redirection(btree->token, fd);
  if ((builtin = my_check_builtin(btree->token)) != -1)
    return (my_builtin(shell, btree->token, fd));
  if ((pid = fork()) == 0)
    return (my_son(btree, fd, shell));
  else if (pid == -1)
    return (my_put_error("can't fork... \n"));
  return (my_father(btree, fd, pid, shell));
}

/*
** my_exec_cmd.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 12:46:13 2014 Pierrick Gicquelais
** Last update Thu May 29 18:10:52 2014 Antoine Plaskowski
*/

#define		_POSIX_SOURCE
#define		_BSD_SOURCE
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

static void	my_son(t_btree *btree, t_fd *fd, t_shell *shell)
{
  t_fd		cpy;

  my_cpy_fd(&cpy, fd);
  if (cpy.fd_redir[1] != -1)
    close(cpy.fd_redir[1]);
  cpy.fd_redir[1] = -1;
  my_execve(btree, &cpy, shell);
}

static int	my_father(t_btree *btree, t_fd *fd, int pid)
{
  int		ret;

  if (fd->fd_redir[1] != -1)
    my_aff_redir_dleft(fd);
  my_close_fd(fd);
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

int		my_exec_cmd(t_btree *btree, t_shell *shell)
{
  t_fd		fd;
  int		pid;
  int		ret;

  if (btree == NULL || btree->token == NULL)
    return (1);
  my_init_fd(&fd);
  my_redirection(btree->token, &fd);
  if (fd.fd_redir[1] != -1)
    my_redir_dleft_in_father(btree->token, &fd);
  if ((pid = vfork()) == 0)
    my_son(btree, &fd, shell);
  else if (pid == -1)
    return (my_put_error("can't fork... \n"));
  ret = my_father(btree, &fd, pid);
  if (shell->cd != NULL)
    {
      chdir(shell->cd);
      free(shell->cd);
      shell->cd = NULL;
    }
  return (ret);
}

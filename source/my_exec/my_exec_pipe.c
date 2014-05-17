/*
** my_exec_pipe.c for my_exec_pipe in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Sat May 17 20:02:02 2014 Antoine Plaskowski
*/

#define		_BSD_SOURCE

#include	<stdlib.h>
#include	<unistd.h>
#include        <sys/wait.h>
#include	"my_exec.h"
#include	"my_str.h"

static int	my_close_fd(int fd_0, int fd_1)
{
  if (fd_0 != -1)
    close(fd_0);
  if (fd_1 != -1)
    close(fd_1);
  return (0);
}

static int	my_son(t_btree *btree, char **env, int fd_0, int fd_1)
{
  if (fd_0 != -1)
    my_dup2(fd_0, 0);
  if (fd_1 != -1)
    {
      my_dup2(fd_1, 1);
      return (my_execve(btree, NULL, env));
    }
  return (my_execve(btree, NULL, env));
}

static int	my_exec_dup(t_btree *btree, char **env, int fd_0, int fd_1)
{
  int		pid;
  int		ret;

  if (btree == NULL || btree->token == NULL || btree->token->type != WORD)
    return (1);
  if ((pid = vfork()) == 0)
    return (my_son(btree, env, fd_0, fd_1));
  else if (pid == -1)
    return (my_put_error("can't vfork ...\n"));
  my_close_fd(fd_0, fd_1);
  if (fd_1 == -1)
    {
      waitpid(pid, &ret, WUNTRACED);
      return (WEXITSTATUS(ret));
    }
  return (0);
}

static int	my_recur_pipe(t_btree *btree, char **env, int fd_0)
{
  int		fd_pipe[2];

  if (btree == NULL || btree->token == NULL)
    return (1);
  if (btree->token->type == WORD)
    return (my_exec_dup(btree, env, fd_0, -1));
  else if (btree->token->type == O_PIPE)
    {
      if (my_pipe(fd_pipe))
	return (1);
      if (my_exec_dup(btree->left, env, fd_0, fd_pipe[1]))
	return (1);
      return (my_recur_pipe(btree->right, env, fd_pipe[0]));
    }
  return (1);
}

int		my_exec_pipe(t_btree *btree, char **env)
{
  int		fd_pipe[2];

  if (btree == NULL || btree->token == NULL || btree->token->type != O_PIPE)
    return (1);
  if (my_pipe(fd_pipe))
    return (1);
  if (my_exec_dup(btree->left, env, -1, fd_pipe[1]))
    return (1);
  return (my_recur_pipe(btree->right, env, fd_pipe[0]));
}

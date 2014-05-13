/*
** my_exec_pipe.c for my_exec_pipe in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Wed May 14 01:36:30 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include        <sys/wait.h>
#include	"my_exec.h"
#include	"my_str.h"

static int	my_exec_dup(t_btree *btree, char **env, int fd_0, int fd_1)
{
  int		pid;
  int		ret;

  if (btree == NULL || btree->token == NULL || btree->token->type != WORD)
    return (1);
  if ((pid = my_fork()) == 0)
    {
      if (fd_0 != -1)
	my_dup2(fd_0, 0);
      if (fd_1 != -1)
	{
	  my_putstr("ok", 2);
	  my_dup2(fd_1, 1);
	  return (my_execve(btree, env));
	}
      return (my_execve(btree, env));
    }
  else if (pid == -1)
    return (1);
  if (fd_1 == -1)
    {
      my_putstr("j'attend", 2);
      waitpid(pid, &ret, WUNTRACED);
      my_putstr("bon c'est bon la", 2);
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

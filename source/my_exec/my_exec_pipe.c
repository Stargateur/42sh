/*
** my_exec_pipe.c for my_exec_pipe in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Wed May 14 00:58:03 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_exec.h"
#include	"my_str.h"

static int	my_dup_in(t_btree *btree, char **env, int src)
{
  int		pid;

  if (btree == NULL || btree->token == NULL || btree->token->type != WORD)
    return (1);
  if ((pid = my_fork()) == 0)
    {
      if (dup_in(src, 1) != 1)
	my_putstr("can'tdup2\n", 2);
      close(src);
      return (my_execve(btree, env, 0));
    }
  else if (pid != -1)
    return (0);
  return (1);
}

static int	my_dup_out(t_btree *btree, char **env, int src)
{
  int		pid;

  if (btree == NULL || btree->token == NULL || btree->token->type != WORD)
    return (1);
  if ((pid = my_fork()) == 0)
    {
      if (dup_in(src, 0) != 0)
	my_putstr("can'tdup2\n", 2);
      close(src);
      return (my_execve(btree, env, 1));
    }
  else if (pid != -1)
    return (0);
  return (1);
}

static int	my_recur_pipe(t_btree *btree, char **env, int fd_in)
{
  int		fd_pipe[2];

  if (btree == NULL || btree->token == NULL)
    return (1);
  if (btree->token->type == WORD)
    return (my_dup_in(btree, env, 0, fd_in));
  else if (btree->token->type == O_PIPE)
    {
      if (my_pipe(fd_pipe))
	return (1);
      if (my_dup_in(btree->left, env, 1, fd_pipe[1]))
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
  if (my_dup_in(btree->left, env, 1, fd_pipe[1]))
    return (1);
  return (my_recur_pipe(btree->right, env, fd_pipe[0]));
}

/*
** my_exec_sleft.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 16 13:45:57 2014 Pierrick Gicquelais
** Last update Sat May 17 03:12:07 2014 Antoine Plaskowski
*/

#define		_BSD_SOURCE

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/wait.h>
#include        <signal.h>
#include	"my_str.h"
#include	"my_exec.h"

static int      my_open_file_and_dup(t_btree *btree)
{
  int           fd;

  if (btree == NULL || btree->token == NULL || btree->token->type != WORD)
    return (1);
  if ((fd = my_open_rdonly(btree->token->attribute)) == -1)
    return (1);
  if (my_dup2(fd, 0) != 0)
    return (1);
  return (0);
}

int		my_exec_sleft(t_btree *btree, char **env)
{
  int		pid;
  int		ret;

  if (btree == NULL || btree->token == NULL || btree->token->type != O_RLEFT)
    return (1);
  if ((pid = vfork()) == 0)
    {
      my_open_file_and_dup(btree->right);
      return (my_execve(btree->left, env));
    }
  else if (pid == -1)
    return (1);
  waitpid(pid, &ret, WUNTRACED);
  return (WEXITSTATUS(ret));
}

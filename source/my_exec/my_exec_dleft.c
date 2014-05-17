/*
** my_exec_dleft.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 13:41:16 2014 Pierrick Gicquelais
** Last update Sat May 17 03:05:23 2014 Antoine Plaskowski
*/

#define		_BSD_SOURCE

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/wait.h>
#include        <signal.h>
#include	"my_str.h"
#include	"my_exec.h"

static int	my_father(t_btree *btree, int fd)
{
  t_str		*str;
  char		*tmp;

  if (btree == NULL || btree->token == NULL || btree->token->type != WORD)
    return (1);
  if ((signal(SIGPIPE, SIG_IGN)) == SIG_ERR)
    my_putstr("can't set ignore sigpipe\n", 2);
  str = NULL;
  while ((tmp = my_get_next_line(0)) && my_strcmp(tmp, btree->token->attribute))
    str = my_append_str(str, tmp);
  free(tmp);
  my_aff_all_str(str, fd);
  my_free_all_str(str);
  if ((signal(SIGPIPE, SIG_DFL)) == SIG_ERR)
    my_putstr("can't set default sigpipe\n", 2);
  return (0);
}

int		my_exec_dleft(t_btree *btree, char **env)
{
  int		fd_pipe[2];
  int		pid;
  int		ret;

  if (btree == NULL || btree->token == NULL || btree->token->type != O_RDLEFT)
    return (1);
  if (my_pipe(fd_pipe))
    return (1);
  if ((pid = vfork()) == 0)
    {
      close(fd_pipe[1]);
      my_dup2(fd_pipe[0], 0);
      return (my_execve(btree->left, env));
    }
  else if (pid == -1)
    return (1);
  close(fd_pipe[0]);
  my_father(btree->right, fd_pipe[1]);
  close(fd_pipe[1]);
  waitpid(pid, &ret, WUNTRACED);
  return (WEXITSTATUS(ret));
}

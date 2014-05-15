/*
** my_cmd.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 12:46:13 2014 Pierrick Gicquelais
** Last update Thu May 15 14:45:49 2014 Antoine Plaskowski
*/

#define		_BSD_SOURCE

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

int		my_cmd(t_btree *btree, char **env)
{
  int		pid;
  int		ret;

  if ((pid = vfork()) == 0)
    return (my_execve(btree, env));
  else if (pid == -1)
    return (my_put_error("can't vfork... \n"));
  waitpid(pid, &ret, WUNTRACED);
  return (WEXITSTATUS(ret));
}

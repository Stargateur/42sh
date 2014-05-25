/*
** my_wait_pid.c for my_wait_pid in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat May 24 14:32:24 2014 Antoine Plaskowski
** Last update Sun May 25 12:32:32 2014 Antoine Plaskowski
*/

#define		_POSIX_SOURCE
#include	<stdlib.h>
#include	<signal.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"my_exec.h"
#include	"my_str.h"

int		my_wait_pid(t_pid *pid)
{
  t_pid		*tmp;
  int		ret;

  while (pid != NULL)
    {
      tmp = pid;
      if (waitpid(pid->pid, &ret, WUNTRACED) != pid->pid)
	my_putstr("waitpid error\n", 2);;
      if (WIFEXITED(ret))
	return (WEXITSTATUS(ret));
      if (WIFSIGNALED(ret))
	my_aff_signal(WTERMSIG(ret));
      if (WIFSTOPPED(ret))
	{
	  my_putstr("no job control we kill your prog\n", 2);
	  kill(pid->pid, SIGKILL);
	}
      pid = pid->next;
      free(tmp);
    }
  return (0);
}

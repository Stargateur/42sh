/*
** my_wait_pid.c for my_wait_pid in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat May 24 14:32:24 2014 Antoine Plaskowski
** Last update Sat May 24 14:36:26 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"my_exec.h"

int		my_wait_pid(t_pid *pid)
{
  t_pid		*tmp;
  int		ret;

  while (pid != NULL)
    {
      tmp = pid;
      waitpid(pid->pid, &ret, WUNTRACED);
      pid = pid->next;
      free(tmp);
    }
  return (0);
}

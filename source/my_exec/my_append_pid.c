/*
** my_append_pid.c for my_append_pid in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat May 24 14:24:45 2014 Antoine Plaskowski
** Last update Sat May 24 14:27:22 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_exec.h"
#include	"my_str.h"

t_pid		*my_append_pid(t_pid *old, int pid)
{
  t_pid		*new;

  if ((new = my_malloc(sizeof(t_pid))) == NULL)
    return (old);
  new->pid = pid;
  new->next = old;
  return (new);
}

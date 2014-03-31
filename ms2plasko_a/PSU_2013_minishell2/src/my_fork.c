/*
** my_fork.c for my_fork in /home/plasko_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar  9 18:40:54 2014 Antoine Plaskowski
** Last update Sun Mar  9 18:43:25 2014 Antoine Plaskowski
*/

#include	<unistd.h>
#include	"my_str.h"

int		my_fork(void)
{
  int		pid;

  if ((pid = fork()) == -1)
    my_putstr("error fork\n", 2);
  return (pid);
}

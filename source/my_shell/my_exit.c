/*
** my_exit.c for my_exit in /home/plasko_a/programation/epitech/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May 19 02:32:40 2014 Antoine Plaskowski
** Last update Mon May 19 03:04:23 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_str.h"

int		my_exit(t_shell *shell, t_fd *fd, char **argv)
{
  if (shell == NULL || fd == NULL || argv == NULL)
    return (1);
  shell->exit = 1;
  if (argv[0] != NULL)
    shell->exit_value = my_getnbr(argv[1]);
  return (0);
}

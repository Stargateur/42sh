/*
** my_sleft_redirection.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 13:20:49 2014 Pierrick Gicquelais
** Last update Tue May 13 13:23:37 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_btree.h"
#include	"my_str.h"

int		my_sleft_redirection(char *file)
{
  int		fd;

  if ((fd = open(file, O_CREAT | O_WRONLY | O_APPEND, \
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (1);
  dup2(fd, 1);
  return (0);
}

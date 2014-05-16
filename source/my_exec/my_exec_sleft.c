/*
** my_exec_sleft.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 16 13:45:57 2014 Pierrick Gicquelais
** Last update Fri May 16 13:49:36 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_btree.h"
#include	"my_str.h"
#include	"my_exec.h"

int		my_exec_sleft(t_btree *btree, char **env)
{
  int		fd;
  int		save_fd;

  save_fd = dup(0);
  if (btree == NULL || btree->token == NULL || btree->token->type != O_RLEFT)
    return (1);
  fd = my_open_rdonly(btree->right->token->attribute);
  dup2(fd, 0);
  if (my_exec(btree->left, env))
    {
      dup2(save_fd, 0);
      return (1);
    }
  dup2(save_fd, 0);
  return (0);
}

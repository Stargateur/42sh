/*
** my_exec_dirght.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 13:20:49 2014 Pierrick Gicquelais
** Last update Fri May 16 10:51:04 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_btree.h"
#include	"my_str.h"
#include	"my_exec.h"

int		my_exec_dright(t_btree *btree, char **env)
{
  int		fd;
  int		save_fd;

  save_fd = dup(1);
  if (btree == NULL || btree->token == NULL || btree->token->type != O_RDRIGHT)
    return (1);
  fd = my_open_wrap(btree->right->token->attribute);
  dup2(fd, 1);
  if (my_exec(btree->left, env))
    {
      dup2(save_fd, 1);
      return (1);
    }
  dup2(save_fd, 1);
  return (0);
}

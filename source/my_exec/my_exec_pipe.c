/*
** my_exec_pipe.c for my_exec_pipe in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Tue May 13 22:13:02 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_exec.h"

int		my_exec_pipe(t_btree *btree, char **env)
{
  if (btree == NULL || btree->token == NULL || btree->token->type != O_PIPE)
    return (1);
  my_exec(btree->left, env);
  my_exec(btree->right, env);
  return (0);
}

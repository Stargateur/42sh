/*
** my_exec_and.c for my_exec_and in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Tue May 13 22:09:27 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_exec.h"

int		my_exec_and(t_btree *btree, char **env)
{
  if (btree == NULL || btree->token == NULL || btree->token->type != O_AND)
    return (1);
  if (my_exec(btree->left, env))
    return (1);
  if (my_exec(btree->right, env))
    return (1);
  return (0);
}

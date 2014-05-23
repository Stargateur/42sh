/*
** my_exec_and.c for my_exec_and in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Fri May 23 13:39:23 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_exec.h"

int		my_exec_and(t_btree *btree, t_shell *shell)
{
  if (btree == NULL || btree->token == NULL || btree->token->type != O_AND)
    return (1);
  if (my_exec(btree->left, shell))
    return (1);
  if (my_exec(btree->right, shell))
    return (1);
  return (0);
}

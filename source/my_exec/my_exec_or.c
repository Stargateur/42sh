/*
** my_exec_or.c for my_exec_or in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Fri May 23 13:39:19 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_exec.h"

int		my_exec_or(t_btree *btree, t_shell *shell)
{
  if (btree == NULL || btree->token == NULL || btree->token->type != O_OR)
    return (1);
  if (my_exec(btree->left, shell))
    return (my_exec(btree->right, shell));
  return (0);
}

/*
** my_exec_comma.c for my_exec_comma in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Sun May 18 22:58:36 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_exec.h"

int		my_exec_comma(t_btree *btree, t_shell *shell)
{
  if (btree == NULL || btree->token == NULL || btree->token->type != O_COMMA)
    return (1);
  my_exec(btree->left, shell);
  my_exec(btree->right, shell);
  return (0);
}

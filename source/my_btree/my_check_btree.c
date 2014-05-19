/*
** my_check_btree.c for my_check_btree in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_btree
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 23:08:06 2014 Antoine Plaskowski
** Last update Mon May 19 02:24:39 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"

int		my_check_btree(t_btree *btree)
{
  if (btree == NULL)
    return (0);
  if (btree->token == NULL)
    return (1);
  if (btree->token->type & CMD)
    return (my_check_cmd_btree(btree->token));
  else if (btree->token->type == O_PIPE)
    return (my_check_pipe_btree(btree));
  if (my_check_btree(btree->left))
    return (1);
  else if (my_check_btree(btree->right))
    return (1);
  return (0);
}

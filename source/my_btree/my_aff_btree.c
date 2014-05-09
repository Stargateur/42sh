/*
** my_aff_btree.c for  in /home/gicque_p/rendu/PSU_2013_42sh/source/my_btree
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May  9 14:08:10 2014 Pierrick Gicquelais
** Last update Fri May  9 14:09:54 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_btree.h"
#include	"my_str.h"

int		my_aff_btree(t_btree *btree, const int fd)
{
  if (btree != NULL)
    {
      my_aff_token(btree->left->token, fd);
      my_aff_token(btree->right->token, fd);
    }
}

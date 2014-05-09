/*
** my_free_btree.c for my_free_btree in /home/plasko_a/rendu/PSU_2013_42sh/source/my_btree
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 13:17:22 2014 Antoine Plaskowski
** Last update Fri May  9 13:24:26 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"

void		my_free_btree(t_btree *btree)
{
  if (btree != NULL)
    free(btree);
}

void		my_free_all_btree(t_btree *btree)
{
  if (btree != NULL)
    {
      my_free_all_btree(btree->left);
      my_free_all_btree(btree->right);
      my_free_btree(btree);
    }
}

/*
** my_new_btree.c for  in /home/gicque_p/rendu/PSU_2013_42sh/source/my_btree
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May  9 13:29:54 2014 Pierrick Gicquelais
** Last update Fri May  9 13:35:28 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_btree.h"
#include	"my_str.h"

t_btree		*my_new_btree(void)
{
  t_btree	*btree;

  if ((btree = my_malloc(sizeof(t_btree))) == NULL)
    return (NULL);
  btree->left = NULL;
  btree->right = NULL;
  btree->token = NULL;
  return (btree);
}

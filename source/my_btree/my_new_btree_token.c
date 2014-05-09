/*
** my_new_btree_token.c for my_new_btree_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_btree
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Fri May  9 14:01:06 2014 Antoine Plaskowski
** Last update Fri May  9 14:04:44 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"

t_btree		*my_create_btree_token(t_token *token)
{
  t_btree	*btree;

  if ((btree = my_new_token()) == NULL)
    return (NULL);
  btree->token = token;
  return (btree);
}

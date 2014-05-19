/*
** my_check_pipe_btree.c for my_check_pipe_btree in /home/plasko_a/programation/epitech/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May 19 02:21:37 2014 Antoine Plaskowski
** Last update Mon May 19 02:23:00 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"

int		my_check_pipe_btree(t_btree *btree)
{
  if (btree == NULL || btree->token == NULL || btree->token->type != O_PIPE)
    return (1);
  return (0);
}

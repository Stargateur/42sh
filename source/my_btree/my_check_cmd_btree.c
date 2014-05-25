/*
** my_check_cmd_btree.c for my_check_cmd_btree in /home/plasko_a/programation/epitech/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May 19 00:24:48 2014 Antoine Plaskowski
** Last update Sun May 25 14:14:35 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"

int		my_check_cmd_btree(t_token *token)
{
  int		left;
  int		dleft;
  int		right;
  int		dright;

  if (token == NULL || (token->type & CMD) == 0)
    return (1);
  left = my_nbr_token_o_rleft(token);
  dleft = my_nbr_token_o_rdleft(token);
  dright = my_nbr_token_o_rdright(token);
  right = my_nbr_token_o_rright(token);
  if (left > 1 || dright > 1 || right > 1 || dleft > 1)
    return (1);
  if (left && dleft)
    return (1);
  if (right && dright)
    return (1);
  return (0);
}

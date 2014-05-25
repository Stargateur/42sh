/*
** my_check_pipe_btree.c for my_check_pipe_btree in /home/plasko_a/programation/epitech/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May 19 02:21:37 2014 Antoine Plaskowski
** Last update Sun May 25 14:24:16 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"

static int	my_check_first_pipe(t_btree *btree)
{
  int		left;
  int		dleft;
  int		right;
  int		dright;

  if (btree == NULL || btree->token == NULL || (btree->token->type & CMD) == 0)
    return (1);
  left = my_nbr_token_o_rleft(btree->token);
  dleft = my_nbr_token_o_rdleft(btree->token);
  dright = my_nbr_token_o_rdright(btree->token);
  right = my_nbr_token_o_rright(btree->token);
  if (left > 1 || dright > 1 || right > 1 || dleft > 1)
    return (1);
  if (left && dleft)
    return (1);
  if (right || dright)
    return (1);
  return (0);
}

static int	my_check_last_pipe(t_btree *btree)
{
  int		left;
  int		dleft;
  int		right;
  int		dright;

  if (btree == NULL || btree->token == NULL || (btree->token->type & CMD) == 0)
    return (1);
  left = my_nbr_token_o_rleft(btree->token);
  dleft = my_nbr_token_o_rdleft(btree->token);
  dright = my_nbr_token_o_rdright(btree->token);
  right = my_nbr_token_o_rright(btree->token);
  if (left > 1 || dright > 1 || right > 1 || dleft > 1)
    return (1);
  if (left || dleft)
    return (1);
  if (right && dright)
    return (1);
  return (0);
}

static int	my_check_mid_pipe(t_btree *btree)
{
  int		left;
  int		dleft;
  int		right;
  int		dright;

  if (btree == NULL || btree->token == NULL || (btree->token->type & CMD) == 0)
    return (1);
  left = my_nbr_token_o_rleft(btree->token);
  dleft = my_nbr_token_o_rdleft(btree->token);
  dright = my_nbr_token_o_rdright(btree->token);
  right = my_nbr_token_o_rright(btree->token);
  if (left || dleft || right || dright)
    return (1);
  return (0);
}

static int	my_recur_check_pipe(t_btree *btree)
{
  if (btree == NULL || btree->token == NULL)
    return (1);
  if (btree->token->type == O_PIPE)
    {
      if (my_check_mid_pipe(btree->left))
	return (1);
      return (my_recur_check_pipe(btree->right));
    }
  return (my_check_last_pipe(btree));
}

int		my_check_pipe_btree(t_btree *btree)
{
  if (btree == NULL || btree->token == NULL || btree->token->type != O_PIPE)
    return (1);
  if (my_check_first_pipe(btree->left))
    return (1);
  return (my_recur_check_pipe(btree->right));
}

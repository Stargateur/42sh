/*
** my_exec_word.c for my_exec_word in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Tue May 13 22:07:49 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_exec.h"

int		my_exec_word(t_btree *btree, char **env)
{
  if (btree == NULL || btree->token == NULL || btree->token->type != WORD)
    return (1);
  return (my_cmd(btree, env));
}

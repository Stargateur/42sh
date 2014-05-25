/*
** my_check_cmd_btree.c for my_check_cmd_btree in /home/plasko_a/programation/epitech/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May 19 00:24:48 2014 Antoine Plaskowski
** Last update Sun May 25 10:37:45 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"

int		my_check_cmd_btree(t_token *token)
{
  if (token == NULL || (token->type & CMD) == 0)
    return (1);
  return (0);
}

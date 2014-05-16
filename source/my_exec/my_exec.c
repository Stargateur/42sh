/*
** my_exec.c for my_exec in /home/plasko_a/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 14:48:36 2014 Antoine Plaskowski
** Last update Fri May 16 13:51:20 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

static int	(*g_fct_exec[])(t_btree *btree, char **env) =
{
  &my_exec_pipe,
  &my_exec_comma,
  &my_exec_and,
  &my_exec_or,
  &my_exec_sright,
  &my_exec_dright,
  &my_exec_sleft,
  &my_exec_word,
  NULL,
};

int		my_exec(t_btree *btree, char **env)
{
  static t_uint	tab[] = {O_PIPE, O_COMMA, O_AND, O_OR, O_RRIGHT, O_RDRIGHT, O_RLEFT, WORD, 0};
  t_uint	i;

  if (btree == NULL || btree->token == NULL)
    return (0);
  i = 0;
  while (tab[i] != 0 && g_fct_exec[i] != NULL)
    {
      if (tab[i] == btree->token->type)
	return (g_fct_exec[i](btree, env));
      i++;
    }
  return (my_put_error("you can't be here... 42sh>git blame\n"));
}

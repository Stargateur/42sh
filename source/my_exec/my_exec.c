/*
** my_exec.c for my_exec in /home/plasko_a/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 14:48:36 2014 Antoine Plaskowski
** Last update Wed May 28 21:41:40 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_exec.h"
#include	"my_str.h"

static t_fct_e	g_fct_exec[] =
  {
    {&my_exec_pipe, O_PIPE},
    {&my_exec_comma, O_COMMA},
    {&my_exec_and, O_AND},
    {&my_exec_or, O_OR},
    {&my_exec_cmd, O_RRIGHT},
    {&my_exec_cmd, O_RDRIGHT},
    {&my_exec_cmd, O_RLEFT},
    {&my_exec_cmd, O_RDLEFT},
    {&my_exec_cmd, WORD},
    {NULL, NONE}
  };

int		my_exec(t_btree *btree, t_shell *shell)
{
  t_uint	i;

  if (btree == NULL || btree->token == NULL || shell == NULL)
    return (0);
  if (shell->exit)
    return (0);
  i = 0;
  while (g_fct_exec[i].fct != NULL)
    {
      if (g_fct_exec[i].type == btree->token->type)
	return (g_fct_exec[i].fct(btree, shell));
      i++;
    }
  return (my_put_error("you can't be here... git blame\n"));
}

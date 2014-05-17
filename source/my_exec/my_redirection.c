/*
** my_redirection.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 13:12:19 2014 Pierrick Gicquelais
** Last update Sat May 17 19:48:11 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

static s_fct_r	g_fct_redir[] =
  {
    {my_redir_left, O_RLEFT},
    {my_redir_dleft, O_RDLEFT},
    {my_redir_right, O_RRIGHT},
    {my_redir_dright, O_RDRIGHT},
    {NULL, NONE}
  };

int		my_redirection(t_token *token, t_fd *fd)
{
  t_token	*tmp;
  int		i;

  if (token == NULL || fd == NULL)
    return (1);
  i = 0;
  while (g_fct_redir[i].fct != NULL)
    {
      if ((tmp = my_found_token(token, g_fct_redir[i].type)) != NULL)
	g_fct_redir[i].fct(tmp->next, fd);
      i++;
    }
  return (0);
}

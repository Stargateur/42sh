/*
** my_redirection.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 13:12:19 2014 Pierrick Gicquelais
** Last update Tue May 13 13:44:54 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

static	int	(g_fct[5]) =
{
  O_RRIGHT,
  O_RDRIGHT,
  O_RLEFT,
  O_RDLEFT,
  0
};

static	int	(*g_ptr[5])(char *) =
{
  &my_sright_redirection,
  &my_dright_redirection,
  &my_sleft_redirection,
  &my_dright_redirection,
  NULL
};

int		my_redirection(char *att, int type)
{
  int		i;

  i = 0;
  while (g_fct[i] && g_fct[i] != type)
    i++;
  if (g_ptr[i] == NULL)
    return (1);
  g_ptr[i](att);
  return (0);
}

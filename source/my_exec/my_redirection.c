/*
** my_redirection.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 13:12:19 2014 Pierrick Gicquelais
** Last update Tue May 13 13:20:18 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_btree.h"
#include	"my_str.h"

int		my_redirection(char *att, int type)
{
  if (type == O_RRIGHT)
    my_sleft_redirection(att);
  else if (type == O_RDRIGHT)
    my_putstr("C'est une redir double gauche\n", 1);
  else if (type == O_RLEFT)
    my_putstr("C'est une redir droite\n", 1);
  else if (type == O_RDLEFT)
    my_putstr("C'est une redir double droite\n", 1);
  return (0);
}

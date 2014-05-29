/*
** my_len_history.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 15:05:43 2014 Pierrick Gicquelais
** Last update Thu May 29 15:06:53 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_history.h"

int		my_len_history(t_histo *history)
{
  t_histo	*tmp;
  int		cmp;

  cmp = 0;
  tmp = my_first_history(history);
  while (tmp)
    {
      tmp = tmp->next;
      cmp++;
    }
  return (cmp);
}

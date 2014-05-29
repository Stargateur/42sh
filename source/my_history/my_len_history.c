/*
** my_len_history.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 15:05:43 2014 Pierrick Gicquelais
** Last update Thu May 29 15:40:46 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_history.h"

int		my_len_history(t_histo *history)
{
  int		cmp;

  cmp = 0;
  history = my_first_history(history);
  while (history)
    {
      history = history->next;
      cmp++;
    }
  return (cmp);
}

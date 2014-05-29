/*
** my_free_history.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 28 18:37:34 2014 Pierrick Gicquelais
** Last update Wed May 28 18:37:38 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_history.h"

void		my_free_history(t_histo *history)
{
  if (history != NULL)
    {
      free(history->att);
      free(history);
    }
}

void		my_free_all_history(t_histo *history)
{
  t_histo	*tmp;

  history = my_first_history(history);
  while (history != NULL)
    {
      tmp = history;
      history = history->next;
      my_free_history(tmp);
    }
}

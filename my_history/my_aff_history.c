/*
** my_aff_history.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 19 13:53:24 2014 Pierrick Gicquelais
** Last update Mon May 19 17:42:06 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_history.h"

void		my_aff_history(t_histo *history)
{
  if (history != NULL)
    {
      my_putchar(' ', 1);
      my_putnbr(history->id, 1);
      my_putchar('\t', 1);
      my_putstr(history->att, 1);
      my_putchar('\n', 1);
    }
}

void		my_aff_all_history(t_histo *history)
{
  history = my_first_history(history);
  while (history != NULL)
    {
      my_aff_history(history);
      history = history->next;
    }
}

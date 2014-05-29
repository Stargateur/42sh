/*
** my_node_history.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 28 18:36:54 2014 Pierrick Gicquelais
** Last update Wed May 28 18:36:55 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_history.h"

t_histo		*my_first_history(t_histo *history)
{
  if (history != NULL)
    while (history->prev != NULL)
      history = history->prev;
  return (history);
}

t_histo		*my_last_history(t_histo *history)
{
  if (history != NULL)
    while (history->next != NULL)
      history = history->next;
  return (history);
}

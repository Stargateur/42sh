/*
** my_new_histo.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 19 13:47:52 2014 Pierrick Gicquelais
** Last update Mon May 19 14:04:30 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_history.h"

t_histo		*my_new_history(void)
{
  t_histo	*history;

  if ((history = malloc(sizeof(t_histo))) == NULL)
    return (NULL);
  history->prev = NULL;
  history->next = NULL;
  history->id = 0;
  history->att = NULL;
  return (history);
}

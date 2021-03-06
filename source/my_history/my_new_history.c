/*
** my_new_history.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 28 18:36:45 2014 Pierrick Gicquelais
** Last update Thu May 29 15:45:03 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_history.h"

t_histo		*my_new_history(void)
{
  t_histo	*history;

  if ((history = my_malloc(sizeof(t_histo))) == NULL)
    return (NULL);
  history->prev = NULL;
  history->next = NULL;
  history->id = 0;
  history->att = NULL;
  return (history);
}

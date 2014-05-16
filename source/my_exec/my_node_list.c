/*
** my_node_list.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 16 14:11:30 2014 Pierrick Gicquelais
** Last update Fri May 16 14:12:40 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_exec.h"

t_list		*my_first_elem(t_list *list)
{
  if (list != NULL)
    while (list->prev != NULL)
      list = list->prev;
  return (list);
}

t_list		*my_last_elem(t_list *list)
{
  if (list != NULL)
    while (list->next != NULL)
      list = list->next;
  return (list);
}

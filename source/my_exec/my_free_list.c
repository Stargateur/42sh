/*
** my_free_list.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 16 14:16:15 2014 Pierrick Gicquelais
** Last update Fri May 16 14:18:00 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_exec.h"

void		my_free_list(t_list *list)
{
  if (list != NULL)
    {
      free(list->att);
      free(list);
    }
}

void		my_free_all_list(t_list *list)
{
  t_list	*tmp;

  list = my_first_elem(list);
  while (list)
    {
      tmp = list;
      list = list->next;
      my_free_list(tmp);
    }
}

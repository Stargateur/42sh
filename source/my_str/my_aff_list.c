/*
** my_aff_list.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 16 14:18:12 2014 Pierrick Gicquelais
** Last update Fri May 16 14:22:59 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_exec.h"

void		my_aff_list(t_list *list)
{
  if (list && list->att)
    {
      my_putstr(list->att, 1);
      my_putstr("\n", 1);
    }
}

void		my_aff_all_list(t_list *list)
{
  list = my_first_elem(list);
  while (list)
    {
      my_aff_list(list);
      list = list->next;
    }
}

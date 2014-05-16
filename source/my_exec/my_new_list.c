/*
** my_new_list.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 16 14:10:04 2014 Pierrick Gicquelais
** Last update Fri May 16 14:20:42 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_exec.h"

t_list		*my_new_list(void)
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->prev = NULL;
  list->next = NULL;
  list->att = NULL;
  return (list);
}

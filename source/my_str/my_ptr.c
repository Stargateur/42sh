/*
** my_ptr.c for my_ptr in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May  6 23:15:49 2014 Antoine Plaskowski
** Last update Tue May  6 23:53:53 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

t_ptr		*my_put_ptr(t_ptr *old, t_ptr *ptr)
{
  if ((old = my_first_ptr(old)) != NULL)
    old->next = ptr;
  if (ptr != NULL)
    ptr->prev = old;
  return (ptr);
}

t_ptr		*my_sup_ptr(t_ptr *ptr)
{
  if (ptr == NULL)
    return (NULL);
  if (ptr->prev != NULL)
    {
      ((t_ptr *)ptr->prev)->next = ptr->next;
      if (ptr->next != NULL)
	((t_ptr *)ptr->next)->prev = ptr->prev;
      return (my_first_ptr(ptr));
    }
  else if (ptr->next != NULL)
    {
      ((t_ptr *)ptr->next)->prev = ptr->prev;
      return (ptr->next);
    }
  return (NULL);
}

t_ptr		*my_first_ptr(t_ptr *ptr)
{
  if (ptr != NULL)
    while (ptr->prev != NULL)
      ptr = ptr->prev;
  return (ptr);
}

t_ptr		*my_last_ptr(t_ptr *ptr)
{
  if (ptr != NULL)
    while (ptr->next != NULL)
      ptr = ptr->next;
  return (ptr);
}

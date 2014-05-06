/*
** my_ptr.c for my_ptr in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May  6 23:15:49 2014 Antoine Plaskowski
** Last update Tue May  6 23:18:37 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_link_ptr(t_ptr *ptr_1, t_ptr *ptr_2)
{
  if (ptr_1 == NULL || ptr_2 == NULL)
    return (1);
  ptr_1->next = ptr_2;
  ptr_2->prev = ptr_1;
  return (0);
}

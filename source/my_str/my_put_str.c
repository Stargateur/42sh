/*
** my_put_str.c for my_put_str in /home/plasko_a/rendu/PSU_2013_42sh/source/my_str
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 17:57:00 2014 Antoine Plaskowski
** Last update Sat May 17 02:35:22 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

t_str		*my_put_str(t_str *old, t_str *str)
{
  if ((old = my_last_str(old)) != NULL)
    old->next = str;
  if (str != NULL)
    {
      str->prev = old;
      str->next = NULL;
    }
  return (str);
}

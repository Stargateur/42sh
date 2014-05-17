/*
** my_str.c for my_str in /home/plasko_a/rendu/PSU_2013_minitalk
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Feb 25 19:06:12 2014 Antoine Plaskowski
** Last update Sat May 17 01:37:40 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_str.h"

t_str		*my_first_elem_str(t_str *str)
{
  if (str != NULL)
    while (str->prev != NULL)
      str = str->prev;
  return (str);
}

t_str		*my_put_str(t_str *old, char *str)
{
  t_str		*new;

  if ((new = my_malloc(sizeof(t_str))) == NULL)
    return (NULL);
  new->str = str;
  new->next = NULL;
  new->prev = NULL;
  if (old != NULL)
    {
      while (old->next != NULL)
	old = old->next;
      new->prev = old;
      old->next = new;
    }
  return (new);
}

void		my_free_all_str(t_str *str)
{
  t_str		*tmp;

  str = my_first_elem_str(str);
  while (str != NULL)
    {
      tmp = str;
      str = str->next;
      my_free_str(tmp);
    }
}

void		my_free_str(t_str *str)
{
  if (str != NULL)
    free(str->str);
  free(str);
}

int		my_aff_str(t_str *str, const int fd)
{
  str = my_first_elem_str(str);
  while (str != NULL)
    {
      my_putstr(str->str, fd);
      my_putchar('\n', fd);
      str = str->next;
    }
  return (0);
}

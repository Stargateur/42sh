/*
** my_free_str.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 16 14:16:15 2014 Pierrick Gicquelais
** Last update Sat May 17 02:39:58 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

void		my_free_str(t_str *str)
{
  if (str != NULL)
    {
      free(str->str);
      free(str);
    }
}

void		my_free_all_str(t_str *str)
{
  t_str		*tmp;

  str = my_first_str(str);
  while (str != NULL)
    {
      tmp = str;
      str = str->next;
      my_free_str(tmp);
    }
}

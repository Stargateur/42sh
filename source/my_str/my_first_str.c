/*
** my_first_str.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 16 14:11:30 2014 Pierrick Gicquelais
** Last update Sat May 17 02:31:40 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

t_str		*my_first_str(t_str *str)
{
  if (str != NULL)
    while (str->prev != NULL)
      str = str->prev;
  return (str);
}

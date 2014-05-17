/*
** my_new_str.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 16 14:10:04 2014 Pierrick Gicquelais
** Last update Sat May 17 02:39:37 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_exec.h"

t_str		*my_new_str(void)
{
  t_str		*str;

  if ((str = malloc(sizeof(t_str))) == NULL)
    return (NULL);
  str->prev = NULL;
  str->next = NULL;
  str->str = NULL;
  return (str);
}

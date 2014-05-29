/*
** my_history.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 28 20:31:22 2014 Pierrick Gicquelais
** Last update Thu May 29 16:00:43 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_history.h"
#include	"my_shell.h"
#include	"my_str.h"

t_histo		*my_history(t_histo *history, char *str)
{
  if (str != NULL && *str != '!')
    history = my_append_history(history, str);
  return (history);
}

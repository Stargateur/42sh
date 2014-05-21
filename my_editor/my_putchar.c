/*
** str.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_editor
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 21 07:55:15 2014 Pierrick Gicquelais
** Last update Wed May 21 08:02:07 2014 Pierrick Gicquelais
*/

#include	<unistd.h>
#include	"my_editor.h"

int		my_putchar(char c)
{
  return (write(1, &c, 1));
}

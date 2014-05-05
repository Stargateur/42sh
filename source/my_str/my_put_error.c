/*
** my_put_error.c for my_put_error in /home/plasko_a/rendu/corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Mar 26 17:11:26 2014 Antoine Plaskowski
** Last update Fri Apr 18 03:48:22 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_put_error(char *str)
{
  my_putstr(str, 2);
  return (1);
}

void		*my_put_error_null(char *str)
{
  my_putstr(str, 2);
  return (NULL);
}

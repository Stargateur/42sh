/*
** my_tgetstr.c for my_tgetstr in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Jan 15 21:51:02 2014 Antoine PLASKOWSKI
** Last update Thu May 29 14:27:06 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_termcaps.h"

char		*my_tgetstr(char *str)
{
  char		*new_str;

  if (str == NULL)
    return (NULL);
  if ((new_str = tgetstr(str, NULL)) == NULL)
    {
      my_putstr(str, 2);
      my_putstr(" : no available\n", 2);
      return (NULL);
    }
  return (new_str);
}

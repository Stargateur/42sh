/*
** my_tgetent.c for my_tgetent in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan 14 14:48:30 2014 Antoine PLASKOWSKI
** Last update Thu May 29 14:26:39 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_termcaps.h"

int		my_tgetent(char *name)
{
  int		status;

  if (name == NULL)
    return (1);
  if ((status = tgetent(NULL, name)) == -1)
    {
      my_putstr("data terminal not found\n", 2);
      return (1);
    }
  else if (status == 0)
    {
      my_putstr(name, 2);
      my_putstr(" is not valid !\n", 2);
      return (1);
    }
  return (0);
}

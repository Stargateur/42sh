/*
** my_reset.c for my_reset in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan 14 15:12:45 2014 Antoine PLASKOWSKI
** Last update Fri May 30 09:56:09 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_termcaps.h"

int		my_reset(t_ter *t)
{
  if (t == NULL)
    return (1);
  if (tcsetattr(0, TCSANOW, t))
    {
      my_putstr("setattr reset fail !\n", 2);
      return (1);
    }
  return (0);
}

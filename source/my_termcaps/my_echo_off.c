/*
** my_echo_off.c for my_echo_off in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan 14 15:07:40 2014 Antoine PLASKOWSKI
** Last update Thu May 29 14:27:20 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_termcaps.h"

int		my_echo_off(t_ter *t)
{
  if (t == NULL)
    return (1);
  t->c_lflag &= ~ECHO;
  if (tcsetattr(0, TCSANOW, t))
    {
      my_putstr("setattr echo fail\n", 2);
      return (1);
    }
  return (0);
}

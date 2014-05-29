/*
** my_tcgetattr.c for my_tcgetattr in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan 14 19:55:21 2014 Antoine PLASKOWSKI
** Last update Thu May 29 14:28:37 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_termcaps.h"

int		my_tcgetattr(t_ter *t)
{
  if (t == NULL)
    return (1);
  if (tcgetattr(0, t))
    {
      my_putstr("tcgectattr FAIL !\n", 1);
      return (1);
    }
  return (0);
}

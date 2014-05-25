/*
** my_aff_signal.c for my_aff_signal in /home/plasko_a/programation/epitech/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 25 12:26:26 2014 Antoine Plaskowski
** Last update Sun May 25 20:39:28 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<signal.h>
#include	"my_str.h"

int		my_aff_signal(int signal)
{
  my_putnbr(signal, 2);
  if (signal == SIGSEGV)
    my_putstr(" : Segmentation fault\n", 2);
  else if (signal == SIGFPE)
    my_putstr(" : Floating point exception\n", 2);
  else
    my_putstr(" : Process terminal by this signal\n", 2);
  return (0);
}

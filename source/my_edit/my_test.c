/*
** my_test.c for my_test in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_edit
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu May 29 18:48:15 2014 Antoine Plaskowski
** Last update Thu May 29 19:04:55 2014 Antoine Plaskowski
*/

#include	"my_termcaps.h"

int		my_test(void)
{
  t_ter		t;
  t_ter		save;
  int		i = 0;
  char		*str;

  my_tcgetattr(&t);
  my_tcgetattr(&save);
  my_echo_off(&t);
  my_raw_mode(&t);
  str = my_tgetstr("kl");
  while (i++ < 42)
    tputs(str, 0, &my_putint);
  my_reset(&save);
}

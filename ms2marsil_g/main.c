/*
** ms1.c for ms1 in /home/marsil_g/Documents/PSU/PSU-MS1/MS
**
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
**
** Started on  Wed Dec 18 14:14:36 2013 Gabriele Marsili
** Last update Sun Mar  9 13:36:00 2014 marsil_g
*/

#include	<signal.h>
#include	"my.h"

int		main(int ac, char **av, char **environ)
{
  (void)ac;
  (void)av;
  signal(SIGINT, SIG_IGN);
  my_putstr("$> ");
  init_all(environ);
  return (0);
}

/*
** echo.c for echo in /home/marsil_g/Documents/PSU/42sh
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Fri May 16 14:18:51 2014 Gabriele Marsili
** Last update Thu May 22 16:20:06 2014 Gabriele Marsili
*/

#include	<stdlib.h>
#include	"includes.h"
#include	"my_str.h"

void		get_opt(char *str, t_echo *opt)
{
  int		i;

  i = 0;
  while (str[++i])
    {
      if (str[i] == 'n')
	opt->t_n = 1;
      else if (str[i] == 'e')
	opt->t_e = 1;
      else if (str[i] == 'E')
	opt->t_e = 0;
    }
}

void		go_echo(char **tab)
{
  t_echo	*opt;

  opt = malloc(sizeof(*opt));
  opt->t_n = 0;
  opt->t_e = 0;
  opt->start = 0;
  my_check_echo(tab, opt);
  norm_echo(tab, opt);
}

void		my_echo()
{
  char		**comm;
  char		*str;

  while ((str = get_next_line(0)) != NULL)
    {
      comm = my_str_to_tab(my_epur_str(str), " ");
      if (my_strcmp(comm[0], "echo") == 0)
	go_echo(comm);
    }
}

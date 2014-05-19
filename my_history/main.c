/*
** main.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 19 13:57:42 2014 Pierrick Gicquelais
** Last update Mon May 19 18:05:21 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_history.h"

char		*my_get_next_line(int);

static char	*my_get_line(int fd)
{
  char		*s;

  my_putstr("History> ", 1);
  s = my_get_next_line(fd);
  return (s);
}

int		main()
{
  t_histo	*history;
  char		*s;
  int		cmp;

  cmp = 1;
  history = NULL;
  while ((s = my_get_line(0)))
    {
      if (s[0])
	{
	  if (check_cmd(history, s))
	    if ((history = my_append_history(history, &cmp, s)) == NULL)
	      return (1);
	  check_history(history, s);
	}
      free(s);
    }
  my_free_all_history(history);
  return (0);
}

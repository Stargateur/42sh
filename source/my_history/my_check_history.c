/*
** check.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 19 14:42:28 2014 Pierrick Gicquelais
** Last update Thu May 29 16:09:36 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_history.h"
#include	"my_str.h"

static int	check_exist_history(t_histo *history)
{
  if (history == NULL)
    {
      my_putstr("History: event not found\n", 1);
      return (1);
    }
  my_putstr("You want to access to history: ", 1);
  my_putstr(history->att, 1);
  my_putchar('\n', 1);
  return (0);
}

static char	*check_minus(t_histo *history, int nbr)
{
  history = my_last_history(history);
  while (history != NULL && ++nbr < 0)
    history = history->prev;
  if (check_exist_history(history))
    return (NULL);
  return (my_strdup(history->att));
}

static char	*check_nbr(t_histo *history, int nbr)
{
  history = my_first_history(history);
  while (history != NULL && history->id != nbr)
    history = history->next;
  if (check_exist_history(history))
    return (NULL);
  return (my_strdup(history->att));
}

static char	*check_string(t_histo *history, char *str)
{
  int		len;

  len = my_strlen(str);
  history = my_last_history(history);
  while (history != NULL && my_strncmp(history->att, str, len))
    history = history->prev;
  if (check_exist_history(history))
    return (NULL);
  return (my_strdup(history->att));
}

char		*check_line(t_histo *history, char *str)
{
  int		nbr;

  if (str == NULL)
    return (NULL);
  if (*str == '!')
    {
      nbr = my_getnbr(str + 1);
      if (nbr < 0)
	return (check_minus(history, nbr));
      else if (nbr > 0)
	return (check_nbr(history, nbr));
      else
	return (check_string(history, str + 1));
    }
  return (my_strdup(str));
}

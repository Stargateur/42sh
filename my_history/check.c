/*
** check.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 19 14:42:28 2014 Pierrick Gicquelais
** Last update Mon May 19 18:37:23 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_history.h"

char		*my_strldup(char *, char, int);

static int	aff_history(t_histo *history)
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

static int	check_minus(t_histo *history, char *s)
{
  char		*att;
  int		cmp;

  cmp = 1;
  if ((att = my_strldup(s, '\0', 2)) == NULL)
    return (1);
  if (s[1] && s[1] == '-')
    {
      while (history && cmp < my_getnbr(att))
	{
	  history = history->prev;
	  cmp++;
	}
      free(att);
      aff_history(history);
      return (0);
    }
  free(att);
  return (1);
}

static int	check_nbr(t_histo *history, char *s)
{
  char		*att;

  if ((att = my_strldup(s, '\0', 1)) == NULL)
    return (1);
  if (!my_ispos(att))
    {
      history = my_first_history(history);
      while (history && history->id != my_getnbr(att))
	history = history->next;
      free(att);
      if (aff_history(history))
	return (1);
      return (0);
    }
  free(att);
  return (1);
}

static int	check_string(t_histo *history, char *s)
{
  char		*att;

  if ((att = my_strldup(s, '\0', 1)) == NULL)
    return (1);
  if (my_is_num(att))
    {
      history = my_first_history(history);
      while (history && my_strcmp(history->att, att))
	history = history->next;
      free(att);
      aff_history(history);
      return (0);
    }
  free(att);
  return (1);
}

int		check_cmd(t_histo *history, char *s)
{
  if (s[0] && s[0] == '!')
    {
      if (!(check_minus(history, s)))
	return (0);
      else if (!(check_nbr(history, s)))
	return (0);
      else if (!(check_string(history, s)))
	return (0);
    }
  return (1);
}

void		check_history(t_histo *history, char *s)
{
  if (!strcmp(s, "history"))
    my_aff_all_history(history);
}

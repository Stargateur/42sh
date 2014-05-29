/*
** check.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 19 14:42:28 2014 Pierrick Gicquelais
** Last update Wed May 28 22:23:42 2014 Pierrick Gicquelais
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

static char	*check_minus(t_histo *history, char *s)
{
  char		*att;

  if ((att = my_strldup(s, '\0', 2)) == NULL)
    return (NULL);
  if (s[1] && s[1] == '-')
    {
      while (history && history->id != my_getnbr(att))
	history = history->prev;
      free(att);
      if (check_exist_history(history))
	return (NULL);
      return (history->att);
    }
  free(att);
  return (NULL);
}

static char	*check_nbr(t_histo *history, char *s)
{
  char		*att;

  if ((att = my_strldup(s, '\0', 1)) == NULL)
    return (NULL);
  if (!is_positive(att))
    {
      while (history && history->id != my_getnbr(att))
	history = history->prev;
      free(att);
      if (check_exist_history(history))
	return (NULL);
      return (history->att);
    }
  free(att);
  return (NULL);
}

static char	*check_string(t_histo *history, char *s)
{
  char		*att;

  if ((att = my_strldup(s, '\0', 1)) == NULL)
    return (NULL);
  if (my_is_num(att))
    {
      while (history && my_strncmp(history->att, att, my_strlen(att)))
	history = history->prev;
      free(att);
      if (check_exist_history(history))
	return (NULL);
      return (history->att);
    }
  free(att);
  return (NULL);
}

char		*check_line(t_histo *history, char *s)
{
  char		*new_s;

  if (s[0] && s[0] == '!')
    {
      history = my_last_history(history);
      if ((new_s = check_minus(history, s)))
	return (new_s);
      else if ((new_s = check_nbr(history, s)))
	return (new_s);
      else if ((new_s = check_string(history, s)))
	return (new_s);
    }
  return (s);
}
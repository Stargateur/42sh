/*
** my_str_to_tab.c for my_str_to_tab in /home/plasko_a/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Oct  9 23:29:57 2013 Antoine Plaskowski
** Last update Tue May 13 18:02:54 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_typedef.h"

static t_uint	my_calc_len_tab(const char *str, const char *delim)
{
  t_uint	i;

  i = 0;
  while (*str != '\0')
    {
      while (my_char_in_str(*str, delim) != -1)
	str++;
      if (*str != '\0')
	i++;
      while (my_char_in_str(*str, delim) == -1 && *str != '\0')
	str++;
    }
  return (sizeof(char *) * (i + 1));
}

static t_uint	my_calc_len_word(const char *str, const char *delim)
{
  t_uint	i;

  i = 0;
  while (my_char_in_str(*str, delim) == -1 && str[i] != '\0')
    i++;
  return (sizeof(char) * (i + 1));
}

char		**my_str_to_tab(const char *str, const char *delim)
{
  char		**tab;
  t_uint	i;
  t_uint	j;

  if (str == NULL)
    return (NULL);
  if ((tab = my_malloc(my_calc_len_tab(str, delim))) == NULL)
    return (NULL);
  i = 0;
  while (*str != '\0')
    {
      while (my_char_in_str(*str, delim) != -1)
	str++;
      if (*str != '\0')
	{
	  if ((tab[i] = my_malloc(my_calc_len_word(str, delim))) == NULL)
	    return (NULL);
	  j = 0;
	  while (my_char_in_str(*str, delim) == -1 && *str != '\0')
	    tab[i][j++] = *str++;
	  tab[i++][j] = '\0';
	}
    }
  tab[i] = NULL;
  return (tab);
}

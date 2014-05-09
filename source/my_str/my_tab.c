/*
** my_tab.c for my_tab in /home/plasko_a/rendu/lem_in/sources/str
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Apr 16 10:50:52 2014 Antoine Plaskowski
** Last update Fri May  9 13:33:46 2014 Gabriele Marsili
*/

#include	<stdlib.h>
#include	"my_str.h"

void		my_free_tab(char **tab)
{
  t_uint	i;

  if (tab != NULL)
    {
      i = 0;
      while (tab[i] != NULL)
	free(tab[i++]);
      free(tab);
    }
}

char		**my_cpy_tab(char **tab)
{
  char		**new_tab;
  t_uint	i;

  if (tab == NULL)
    return (NULL);
  if ((new_tab = my_calloc(sizeof(char *) * (my_len_tab(tab) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    {
      if ((new_tab[i] = my_strdup(tab[i])) == NULL)
	return (NULL);
      i++;
    }
  new_tab[i] = NULL;
  return (new_tab);
}

int		my_aff_tab(char **tab, const int fd)
{
  if (tab != NULL)
    {
      while (*tab != NULL)
	{
	  my_putstr(*tab++, fd);
	  my_putchar(' ', fd);
	}
      my_putchar('\n', fd);
    }
  return (0);
}

t_uint		my_len_tab(char **tab)
{
  t_uint	i;

  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      i++;
  return (i);
}

/*
** my_str_in_tab.c for my_str_in_tab in /home/plasko_a/rendu/epic_js_fantasy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 11 06:04:14 2014 Antoine Plaskowski
** Last update Sun May 11 06:32:24 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_str_in_tab(char **tab, const char *str)
{
  int		i;

  if (str != NULL && tab != NULL)
    {
      i = 0;
      while (tab[i] != NULL)
	{
	  if (my_strcmp(tab[i], str) == 0)
	    return (i);
	  i++;
	}
    }
  return (-1);
}

int		my_str_in_tab_icase(char **tab, const char *str)
{
  int		i;

  if (str != NULL && tab != NULL)
    {
      i = 0;
      while (tab[i] != NULL)
	{
	  if (my_strcmp_icase(tab[i], str) == 0)
	    return (i);
	  i++;
	}
    }
  return (-1);
}

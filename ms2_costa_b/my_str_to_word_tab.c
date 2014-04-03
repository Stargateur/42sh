/*
** my_str_to_word_tab.c for my_str_to_word_tab in /home/costa_b/rendu/usefull
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Tue Feb 25 17:19:54 2014 Kevin Costa
** Last update Fri Mar  7 13:04:47 2014 Kevin Costa
*/

#include	<stdlib.h>
#include	"my.h"

int		my_nb_word(char *str)
{
  int		i;

  i = 0;
  while (*str)
    {
      while (*str == ' ' || *str == '\t')
	str++;
      if (*str != ' ' && *str != '\t' && *str != '\0')
	i++;
      while (*str != ' ' && *str != '\t' && *str != '\0')
	str++;
    }
  return (i + 1);
}

int		my_nb_letter(char *str)
{
  int		i;

  i = 0;
  while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
    i++;
  return (i + 1);
}

char		**my_str_to_wordtab(char *str)
{
  char		**wordtab;
  int		i;
  int		j;

  if (str == NULL)
    return (NULL);
  if ((wordtab = malloc(sizeof(char *) * my_nb_word(str))) == NULL)
    return (NULL);
  i = 0;
  while (*str)
    {
      while (*str == ' ' || *str == '\t')
	str++;
      if (*str != ' ' && *str != '\t' && *str != '\0')
	{
	  if ((wordtab[i] = malloc(sizeof(char) * my_nb_letter(str))) == NULL)
	    return (NULL);
	  j = 0;
	  while (*str != ' ' && *str != '\t' && *str != '\0')
	    wordtab[i][j++] = *str++;
	  wordtab[i++][j] = '\0';
	}
    }
  wordtab[i] = NULL;
  return (wordtab);
}

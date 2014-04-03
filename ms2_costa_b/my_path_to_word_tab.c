/*
** my_path_to_wordtab.c for my_path_to_wordtab in /home/costa_b/rendu/PSU_2013_minishell2
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Fri Mar  7 15:11:36 2014 Kevin Costa
** Last update Fri Mar  7 18:19:36 2014 Kevin Costa
*/

#include	<stdlib.h>
#include	"my.h"

int             my_nb_pathword(char *str)
{
  int           i;

  i = 0;
  while (*str)
    {
      while (*str == ':' || *str == '\t')
        str++;
      if (*str != ':' && *str != '\t' && *str != '\0')
        i++;
      while (*str != ':' && *str != '\t' && *str != '\0')
        str++;
    }
  return (i + 1);
}

int             my_nb_pathletter(char *str)
{
  int           i;

  i = 0;
  while (str[i] != ':' && str[i] != '\t' && str[i] != '\0')
    i++;
  return (i + 1);
}

char            **my_str_to_pathtab(char *str)
{
  char          **p;
  int           i;
  int           j;

  if (str == NULL)
    return (NULL);
  if ((p = malloc(sizeof(char *) * my_nb_pathword(str))) == NULL)
    return (NULL);
  i = 0;
  while (*str)
    {
      while (*str == ':' || *str == '\t')
        str++;
      if (*str != ':' && *str != '\t' && *str != '\0')
        {
          if ((p[i] = malloc(sizeof(char) * my_nb_pathletter(str))) == NULL)
            return (NULL);
          j = 0;
          while (*str != ':' && *str != '\t' && *str != '\0')
	    p[i][j++] = *str++;
          p[i++][j] = '\0';
        }
    }
  p[i] = NULL;
  return (p);
}

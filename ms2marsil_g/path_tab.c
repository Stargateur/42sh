/*
** my_str_to_wordtab.c for str to word in /home/marsil_g/Documents/PSU/PSU-MS1/MS
**
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
**
** Started on  Fri Dec 20 13:19:21 2013 Gabriele Marsili
** Last update Sat Mar  8 16:02:43 2014 marsil_g
*/

#include	<stdlib.h>
#include	"my.h"

int		linecount(char *str)
{
  int		i;
  int		c;

  i = 0;
  c = 0;
  while (str[i])
    {
      if (str[i] == ':')
        c++;
      i++;
    }
  return (c + 1);
}

char		**boucle(char *str, char **dest, int i, int j)
{
  int		k;

  while (str[i])
    {
      k = 0;
      if ((dest[j] = malloc(my_strlen(str) + 2)) == NULL)
	my_err_mall("boucle");
      while (str[i] && str[i] != ':')
        {
          dest[j][k] = str[i];
          i++;
          k++;
	  if (str[i] == 0)
	    return (dest);
	}
      dest[j][k++] = '/';
      dest[j][k] = '\0';
      i++;
      j++;
    }
  dest[j + 1] = '\0';
  return (dest);
}

char		**my_path_to_wordtab(char *str)
{
  char		**dest;
  int		i;
  int		j;

  i = 5;
  j = 0;
  if ((dest = malloc(sizeof (char*) * (linecount(str) + 1))) == NULL)
    my_err_mall("my_path_to_wordtab");
  dest = boucle(str, dest, i, j);
  free(str);
  return (dest);
}

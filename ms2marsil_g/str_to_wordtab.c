/*
** my_str_to_wordtab.c for str_to_word in /home/marsil_g/Desktop/Divers
**
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
**
** Started on  Mon Jan  6 16:16:58 2014 Gabriele Marsili
** Last update Sat Mar  8 16:01:53 2014 marsil_g
*/

#include	<stdlib.h>
#include	"my.h"

int		n_mots(char *str)
{
  int		j;
  int		i;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      while (!((str[i] > 47 && str[i] < 58) || (str[i] > 64 && str[i] < 91) \
	       || (str[i] > 96 && str[i] < 123)) && str[i] != '\0')
	i++;
      while (((str[i] > 47 && str[i] < 58) || (str[i] > 64 && str[i] < 91)
	      || (str[i] > 96 && str[i] < 123)) && str[i] != '\0')
	i++;
      j++;
    }
  return (j);
}

char		**norm_boucle(char *str, char **dest, int i, int j)
{
  int		k;

  while (str[i] != 0)
    {
      k = 0;
      if ((dest[j] = malloc(my_strlen(str) + 1)) == NULL)
	my_err_mall("norm_boucle");
      while (str[i] != ' ')
        {
          dest[j][k] = str[i];
          i++;
          k++;
          if (str[i] == 0)
            return (dest);
        }
      dest[j][k] = '\0';
      i++;
      j++;
    }
  dest[j] = NULL;
  return (dest);
}

char		**norm_str_to_wordtab(char *str)
{
  char		**dest;
  int		i;
  int		j;

  i = 0;
  if ((dest = malloc(sizeof (char*) * (n_mots(str) + 1))) == NULL)
    my_err_mall("norm_str_to_wordtab");
  j = 0;
  dest = norm_boucle(str, dest, i, j);
  return (dest);
}

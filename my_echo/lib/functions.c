/*
** my_functions.c for my_functions in /home/marsil_g/Documents/PSU/PSU-MS1/MS
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Wed Dec 18 15:37:21 2013 Gabriele Marsili
** Last update Fri May 16 14:26:20 2014 Gabriele Marsili
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"includes.h"

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  while (str[++i]);
  return (i);
}

char		*my_strcat(char *str1, char *str2)
{
  int		i;
  int		j;
  char		*final;

  i = -1;
  j = -1;
  if ((final = malloc(sizeof(char) *
		      (my_strlen(str1) + my_strlen(str2) + 1))) == NULL)
    my_err_mall("my_strcat");
  while (str1[++i])
    final[i] = str1[i];
  while (str2[++j])
    final[i++] = str2[j];
  final[i] = '\0';
  return (final);
}

int		my_getnbr(char *str)
{
  int		i;
  int		res;
  int		dix;

  dix = 10;
  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      while (str[i] < '0' || str[i] > '9')
	{
          if (str[i] == '-')
            dix = - dix;
          else if (str[i] != '+')
            return (res / dix);
          i = i + 1;
        }
      res = (res + (str[i] - 48)) * 10;
      i = i + 1;
      if (i >= 10)
        return (0);
    }
  return (res / dix);
}

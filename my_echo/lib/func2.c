/*
** func2.c for functions in /home/marsil_g/Documents/PSU/PSU-MS1/MS
**
** Made by marsil_g
** Login   <marsil_g@epitech.net>
**
** Started on  Tue Mar  4 17:57:46 2014 marsil_g
** Last update Fri May 16 14:26:29 2014 Gabriele Marsili
*/

#include	<stdlib.h>
#include	"includes.h"

int		check_space(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (1);
    }
  return (0);
}

char		*epur_str(char *str)
{
  char		*dest;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (!str)
    return (0);
  if ((dest = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    my_err_mall("epur_str");
  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i])
    {
      if ((str[i] != ' ' && str[i] != '\t') ||
	  (str[i + 1] != ' ' && str[i + 1] != '\t'))
	dest[j++] = str[i];
      i++;
    }
  dest[j] = '\0';
  if (dest[j - 1] == ' ' || dest[j - 1] == '\t')
    dest[j - 1] = '\0';
  return (dest);
}

int		my_strcmp(char *str, char *str_bis)
{
  int		i;

  if (str == NULL || str_bis == NULL)
    return (0);
  i = 0;
  while (str[i] == str_bis[i] && str[i] != '\0')
    i++;
  return (str[i] - str_bis[i]);
}

void		my_err_mall(char *str)
{
  my_fputstr(2, "Error in allocating memory in function ");
  my_fputstr(2, str);
  exit (EXIT_FAILURE);
}

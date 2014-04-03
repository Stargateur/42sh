/*
** init.c for  in /home/marsil_g/Documents/PSU/PSU-MS1/MS
**
** Made by marsil_g
** Login   <marsil_g@epitech.net>
**
** Started on  Mon Mar  3 17:53:10 2014 marsil_g
** Last update Sat Mar  8 16:10:52 2014 marsil_g
*/

#include	<stdlib.h>
#include	"my.h"

void		my_err_mall(char *s)
{
  my_putstr("Error in allocating memory. Stopping process at function : \n");
  my_putstr(s);
  my_putstr(".\n");
  exit(0);
}

char		*get_path(char **my_env)
{
  int		i;
  int		j;
  int		k;
  char		*res;

  k = 4;
  i = -1;
  j = -1;
  while (my_env[++i])
    {
      if (my_strcmp("PATH=", my_env[i]) == 1)
	{
	  if ((res = malloc(my_strlen(my_env[i]) + 1)) == NULL)
	    my_err_mall("get_path");
	  while (my_env[i][++k] != '\0')
	    res[++j] = my_env[i][k];
	  res[j] = '\0';
	  return (res);
	}
    }
  exit(0);
}

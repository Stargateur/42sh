/*
** ms1.c for ms1 in /home/marsil_g/Documents/PSU/PSU-MS1/MS
**
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
**
** Started on  Wed Feb 19 14:40:43 2014 Gabriele Marsili
** Last update Sat Mar  8 02:02:52 2014 marsil_g
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

char		*get_home(char *pth)
{
  char		*str;
  int		i;
  int		k;

  k = -1;
  i = 4;
  if ((str = malloc(my_strlen(pth))) == 0)
    return (0);
  while (pth[++i] != 0)
    str[++k] = pth[i];
  str[++k] = 0;
  return (str);
}

void		my_exec(char **pth, char **my_env, char **tab)
{
  int		i;

  i = -1;
  while (pth[++i])
    {
      execve(my_strcat(pth[i], tab[0]), tab, my_env);
      free(pth[i]);
    }
  execve(tab[0], tab, my_env);
  my_error(tab[0]);
}

int		linecount1(char **str)
{
  int		i;
  int		j;
  int		c;

  j = 0;
  c = 0;
  while (str[j])
    {
      i = 0;
      while (str[j][i])
	i++;
      j++;
      c++;
    }
  return (c);
}

char		**env_cpy(char **environ)
{
  char		**copy_env;
  int		i;
  int		j;

  j = 0;
  if ((copy_env = malloc(sizeof(char*) * (linecount1(environ) + 1))) == NULL)
    exit(0);
  while (environ[j])
    {
      i = 0;
      if ((copy_env[j] = malloc(my_strlen(environ[j]) + 1)) == NULL)
	exit(0);
      while (environ[j][i] != '\0')
	{
	  copy_env[j][i] = environ[j][i];
	  i++;
	}
      copy_env[j][i] = 0;
      j++;
    }
  copy_env[j] = NULL;
  return (copy_env);
}

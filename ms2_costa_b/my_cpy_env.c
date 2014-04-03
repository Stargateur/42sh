/*
** my_cpy_env.c for my_cpy_env in /home/costa_b/rendu/PSU_2013_minishell2
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Mar  6 18:06:14 2014 Kevin Costa
** Last update Fri Mar  7 18:23:36 2014 Kevin Costa
*/

#include	<stdlib.h>
#include	"my.h"

char		*my_strdup(char *src)
{
  char		*dest;

  if (src == NULL)
    return (NULL);
  if ((dest = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
    return (NULL);
  return (my_strcpy(dest, src));
}

char		**cpy_env(char **env)
{
  char		**new;
  int		i;

  if (env == NULL)
    return (NULL);
  i = 0;
  while (env[i] != NULL)
    i++;
  if ((new = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (env[i] != NULL)
    {
      if ((new[i] = my_strdup(env[i])) == NULL)
	return (NULL);
      i++;
    }
  new[i] = NULL;
  return (new);
}

char		**my_path(char **env)
{
  int		i;
  char		**wordtab;

  i = 0;
  while (env[i])
    {
      if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
	  && env[i][3] == 'H' && env[i][4] == '=')
	{
	  wordtab = my_str_to_pathtab(env[i] + 5);
	  return (wordtab);
	}
      i++;
    }
  my_putstr("PATH doesn't exist\n");
  return (0);
}

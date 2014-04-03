/*
** func2.c for functions in /home/marsil_g/Documents/PSU/PSU-MS1/MS
**
** Made by marsil_g
** Login   <marsil_g@epitech.net>
**
** Started on  Tue Mar  4 17:57:46 2014 marsil_g
** Last update Sun Mar  9 13:35:06 2014 marsil_g
*/

#include	<stdlib.h>
#include	"my.h"

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

int		my_strcmp(char *src, char *comp)
{
  int		i;

  i = -1;
  while (src[++i])
    {
      if (src[i] != comp[i])
        if (src[i] != 0)
          return (0);
    }
  return (1);
}

void		init_all(char **environ)
{
  char		**my_env;
  char		**path;
  char		*str;

  my_env = env_cpy(environ);
  if (my_env[0] == NULL)
    {
      while ((str = get_next_line(0)) != NULL)
	my_putstr("$>");
    }
  else
    {
      str = get_path(my_env);
      path = my_path_to_wordtab(str);
      comm_exec(path, my_env);
    }
}

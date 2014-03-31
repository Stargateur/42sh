/*
** my_tool_env.c for my_tool_env in /home/plasko_a/rendu/PSU_2013_minishell1/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec 15 18:21:05 2013 Antoine Plaskowski
** Last update Sun Feb 23 10:46:23 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_len_name_env(const char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0' && str[i] != '=')
    i++;
  if (str[i] != '=')
    {
      my_putstr("invalid env : ", 2);
      my_putstr(str, 2);
      my_putchar('\n', 2);
      return (-1);
    }
  return (i);
}

int		my_found_env(char **env, const char *str)
{
  int		len;
  int		j;

  if (env == NULL || str == NULL)
    return (-1);
  if ((len = my_len_name_env(str)) == -1)
    return (-1);
  j = 0;
  while (env[j] != NULL && my_strncmp(env[j], str, len))
    j++;
  return (j);
}

int		my_search_env(char **env, const char *name)
{
  int		len;
  int		j;

  if (env == NULL || name == NULL)
    return (-1);
  len = my_strlen(name);
  j = 0;
  while (env[j] != NULL && my_strncmp(env[j], name, len))
    j++;
  return (j);
}

char		*my_var_env(char **env, const char *name)
{
  int		len;

  if (env == NULL || name == NULL)
    return (NULL);
  len = my_strlen(name);
  while (*env != NULL && my_strncmp(*env, name, len))
    env++;
  if (*env != NULL)
    return (*env + len);
  return (NULL);
}

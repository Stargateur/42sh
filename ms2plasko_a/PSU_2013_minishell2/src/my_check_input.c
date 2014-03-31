/*
** my_check_input.c for my_check_input in /home/plasko_a/rendu/PSU_2013_minishell1/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec 15 19:55:20 2013 Antoine Plaskowski
** Last update Sun Mar  9 21:07:41 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_management.h"
#include	"my_check_error.h"
#include	"my_tool_env.h"
#include	"my_mysh.h"
#include	"my_str.h"
#include	"my_dir.h"

static char	*my_found_path_exe(const char *str, const char *path)
{
  char		*new_path;
  DIR		*dir;
  struct dirent	*dp;

  if ((dir = my_open_dir(path)) == NULL)
    return (NULL);
  while ((dp = readdir(dir)) != NULL)
    if (my_strcmp(str, dp->d_name) == 0)
      {
	new_path = my_cat_dir(path, dp->d_name);
	my_close_dir(dir);
	return (new_path);
      }
  my_close_dir(dir);
  return (NULL);
}

static char	*my_path_exe(const char *str, int *i)
{
  char		*path;
  int		j;

  j = 0;
  while (str[*i + j] != ':' && str[*i + j] != '\0')
    j++;
  if ((path = my_malloc(sizeof(char) * (j + 1))) == NULL)
    return (NULL);
  j = 0;
  while (str[*i] != ':' && str[*i] != '\0')
    path[j++] = str[(*i)++];
  path[j] = '\0';
  if (str[*i] == ':')
    (*i)++;
  return (path);
}

static char	*my_check_path(char **env, char *str)
{
  char		*path_var;
  char		*path_tmp;
  char		*path_exe;
  int		i;

  if ((path_var = my_var_env(env, "PATH=")) == NULL)
    return (NULL);
  i = 0;
  while (path_var[i] != '\0')
    {
      if ((path_tmp = my_path_exe(path_var, &i)) == NULL)
	return (NULL);
      if ((path_exe = my_found_path_exe(str, path_tmp)) != NULL)
	{
	  free(path_tmp);
	  return (path_exe);
	}
      free(path_tmp);
    }
  return (NULL);
}

char		*my_found_exe(char **env, char *input)
{
  char		*path;
  char		*tab[6];
  int		i;

  if (env == NULL || input == NULL)
    return (NULL);
  tab[0] = "cd";
  tab[1] = "pwd";
  tab[2] = "setenv";
  tab[3] = "unsetenv";
  tab[4] = "env";
  tab[5] = "exit";
  i = 0;
  while (i < 6)
    if (my_strcmp(input, tab[i++]) == 0)
      return (my_strdup(input));
  if ((path = my_check_path(env, input)) == NULL)
    path = my_strdup(input);
  if (my_check_exe(path))
    {
      free(path);
      return (NULL);
    }
  return (path);
}

/*
** my_check_input.c for my_check_input in /home/plasko_a/rendu/PSU_2013_minishell1/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec 15 19:55:20 2013 Antoine Plaskowski
** Last update Thu May 29 14:42:16 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_exec.h"
#include	"my_str.h"

static char	*my_search_in_dir(const char *str, const char *path)
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

static char	*my_check_path(t_env *env, char *str)
{
  char		**tab;
  char		*path_exe;
  int		i;

  if ((env = my_found_env(env, "PATH")) == NULL)
    return (NULL);
  if ((tab = my_str_to_tab(env->value, ":")) == NULL)
    return (NULL);
  path_exe = NULL;
  i = 0;
  while (tab[i] != NULL && (path_exe = my_search_in_dir(str, tab[i])) == NULL)
    i++;
  my_free_tab(tab);
  return (path_exe);
}

char		*my_found_exe(t_env *env, char *str)
{
  char		*ret;

  if (str == NULL)
    return (NULL);
  if (!is_dir(str))
    ret = my_strdup(str);
  else if ((ret = my_check_path(env, str)) == NULL)
    {
      my_putstr(str, 2);
      return (my_put_error_null(" : can't find exe\n"));
    }
  if (my_check_exe(ret))
    {
      free(ret);
      return (NULL);
    }
  return (ret);
}

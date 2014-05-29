/*
** my_dir.c for my_dir in /home/plasko_a/rendu/PSU_2013_my_ls/src_my_ls
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Nov 29 11:05:43 2013 Antoine Plaskowski
** Last update Thu May 29 18:23:44 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<errno.h>
#include	<unistd.h>
#include	<dirent.h>
#include	"my_str.h"

int		my_chdir(const char *path)
{
  if (path == NULL)
    return (1);
  if (chdir(path))
    {
      my_putstr(path, 2);
      if (errno == EACCES)
	my_putstr(" : permission non accordee\n", 2);
      else
	my_putstr(" : can't find\n", 2);
      return (1);
    }
  return (0);
}

DIR		*my_open_dir(const char *path)
{
  DIR		*dir;

  if (path == NULL)
    {
      my_putstr("path == NULL in open dir\n", 2);
      return (NULL);
    }
  if ((dir = opendir(path)) == NULL)
    {
      my_putstr("can't open ", 2);
      my_putstr(path, 2);
      my_putchar('\n', 2);
      return (NULL);
    }
  return (dir);
}

int		my_close_dir(DIR *dir)
{
  if (dir == NULL)
    {
      my_putstr("dir == NULL in close dir\n", 2);
      return (1);
    }
  if (closedir(dir))
    {
      my_putstr("can't close dir\n", 2);
      return (1);
    }
  return (0);
}

char		*my_cat_dir(const char *dir, const char *name)
{
  char		*new_name;
  int		i;
  int		len;

  if (dir == NULL || name == NULL)
    return (NULL);
  len = my_strlen(dir);
  if (len == 0 || dir[len - 1] != '/')
    i = 2 + len + my_strlen(name);
  else
    i = 1 + len + my_strlen(name);
  if ((new_name = my_malloc(sizeof(char) * i)) == NULL)
    return (NULL);
  my_strcpy(new_name, dir);
  i = len;
  if (len == 0 || dir[len - 1] != '/')
    new_name[i++] = '/';
  while (*name != '\0')
    new_name[i++] = *name++;
  new_name[i] = '\0';
  return (new_name);
}

/*
** my_dir.c for my_dir in /home/plasko_a/rendu/PSU_2013_my_ls/src_my_ls
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Nov 29 11:05:43 2013 Antoine Plaskowski
** Last update Sat Dec 21 21:50:14 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<dirent.h>
#include	"my_str.h"

int		my_chdir(const char *path)
{
  if (chdir(path))
    {
      my_putstr(path, 2);
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
  int		b;

  if (dir == NULL || name == NULL)
    return (NULL);
  if (my_strlen(dir) == 0 || dir[my_strlen(dir) - 1] != '/')
    b = 2 + my_strlen(dir) + my_strlen(name);
  else
    b = 1 + my_strlen(dir) + my_strlen(name);
  if ((new_name = my_malloc(sizeof(char) * b)) == NULL)
    return (NULL);
  i = 0;
  while (dir[i])
    {
      new_name[i] = dir[i];
      i++;
    }
  if (my_strlen(dir) == 0 || dir[my_strlen(dir) - 1] != '/')
    new_name[i++] = '/';
  while (*name)
    new_name[i++] = *name++;
  new_name[i] = '\0';
  return (new_name);
}

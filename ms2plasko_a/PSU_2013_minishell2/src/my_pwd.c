/*
** my_pwd.c for my_pwd in /home/plasko_a/rendu/pwd
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Dec 20 07:36:43 2013 Antoine Plaskowski
** Last update Sun Feb 23 09:11:18 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<dirent.h>
#include	<sys/stat.h>
#include	"my_pwd.h"
#include	"my_dir.h"
#include	"my_str.h"

static t_list	*my_put_list(t_list *list, const char *str)
{
  t_list	*new;

  if ((new = my_malloc(sizeof(t_list))) == NULL)
    return (NULL);
  new->str = my_strdup(str);
  new->next = list;
  return (new);
}

static int	my_len_pwd(t_list *list)
{
  int		result;

  result = 0;
  if (list == NULL)
    result++;
  while (list != NULL)
    {
      result += my_strlen(list->str) + 1;
      list = list->next;
    }
  return (result + 1);
}

static char	*my_cat_list(t_list *list)
{
  t_list	*tmp;
  char		*str;
  int		i;
  int		j;

  if ((str = my_malloc(sizeof(char) * my_len_pwd(list))) == NULL)
    return (NULL);
  i = 0;
  if (list == NULL)
    str[i++] = '/';
  while (list != NULL)
    {
      str[i++] = '/';
      j = 0;
      while (list->str[j] != '\0')
	str[i++] = list->str[j++];
      tmp = list;
      list = list->next;
      free(tmp->str);
      free(tmp);
    }
  str[i] = '\0';
  if (my_chdir(str))
    return (NULL);
  return (str);
}

char		*my_pwd(void)
{
  struct stat	parent;
  struct stat	cur;
  struct dirent	*dp;
  DIR		*dir;
  t_list	*list;

  list = NULL;
  while (42)
    {
      if (stat(".", &parent) || stat("..", &cur) || chdir(".."))
	return (NULL);
      if (cur.st_ino == parent.st_ino && cur.st_dev == parent.st_dev)
	return (my_cat_list(list));
      if ((dir = my_open_dir(".")) == NULL)
	return (NULL);
      while ((dp = readdir(dir)) != NULL)
	{
	  stat(dp->d_name, &cur);
	  if (cur.st_ino == parent.st_ino && cur.st_dev == parent.st_dev)
	    if ((list = my_put_list(list, dp->d_name)) == NULL)
	      return (NULL);
	}
      my_close_dir(dir);
    }
  return (NULL);
}

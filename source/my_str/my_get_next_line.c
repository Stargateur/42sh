/*
** my_get_next_line.c for my_get_next_line in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Feb 12 15:22:30 2014 Antoine Plaskowski
** Last update Sun May 25 14:55:07 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_str.h"

static char	*my_str_new_line(t_str *str)
{
  char		*new_line;
  t_uint	len;
  t_uint	i;

  if (str == NULL)
    return (NULL);
  len = my_strlen(str->str);
  i = 0;
  while (str->prev != NULL)
    {
      i++;
      str = str->prev;
    }
  if ((new_line = my_malloc(sizeof(char) * (i * BUF + len + 1))) == NULL)
    return (NULL);
  return (new_line);
}

static char	*my_cat_str(t_str *str)
{
  t_str		*tmp_str;
  char		*new_line;
  t_uint	i;
  int		j;

  if (str == NULL)
    return (NULL);
  if ((new_line = my_str_new_line(str)) == NULL)
    return (NULL);
  str = my_first_str(str);
  i = 0;
  while (str != NULL)
    {
      j = 0;
      while (str->str[j] != '\0')
	new_line[i++] = str->str[j++];
      tmp_str = str;
      str = str->next;
      my_free_str(tmp_str);
    }
  new_line[i] = '\0';
  return (new_line);
}

static char	*my_new_line(const char *buf, int *i, int max)
{
  char		*str;
  int		j;

  if (buf == NULL || i == NULL)
    return (NULL);
  j = 0;
  while (buf[*i + j] != '\n' && *i + j < max)
    j++;
  if ((str = my_malloc(sizeof(char) * (j + 1))) == NULL)
    return (NULL);
  j = 0;
  while (buf[*i] != '\n' && *i < max)
    str[j++] = buf[(*i)++];
  str[j] = '\0';
  return (str);
}

char		*my_get_next_line(const int fd)
{
  static char	buf[BUF];
  static int	i = 0;
  static int	max = 0;
  t_str		*str;
  char		*new_line;

  str = NULL;
  while (42)
    {
      if (i >= max)
	{
	  i = 0;
	  if ((max = read(fd, buf, BUF)) <= 0)
	    return (my_cat_str(str));
	}
      if ((new_line = my_new_line(buf, &i, max)) == NULL)
	return (my_cat_str(str));
      else
	str = my_append_str(str, new_line);
      if (buf[i++] == '\n')
	return (my_cat_str(str));
    }
  return (NULL);
}

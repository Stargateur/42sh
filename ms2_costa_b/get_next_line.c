/*
** get_next_line.c for get_next_line in /home/costa_b/rendu/PSU_2013_minishell2
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Feb 20 17:26:27 2014 Kevin Costa
** Last update Fri Mar  7 13:10:00 2014 Kevin Costa
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<fcntl.h>
#include	"my.h"

char		*my_strcat(char *str1, char *str2)
{
  char		*new;
  int		i;
  int		j;

  if (str1 == NULL || str2 == NULL)
    return (NULL);
  if (!(new = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1))))
    return (NULL);
  i = 0;
  j = 0;
  while (str1[j] != '\0')
    new[i++] = str1[j++];
  j = 0;
  while (str2[j] != '\0')
    new[i++] = str2[j++];
  new[i] = '\0';
  free(str1);
  free(str2);
  return (new);
}

char		*get_next_line(const int fd)
{
  char		*str;
  static char	buffer[MEM_SIZE];
  int		a;
  int		b;
  int		c;

  a = 0;
  c = 0;
  if ((str = malloc((MEM_SIZE + 1) * sizeof(char))) == NULL)
    return (NULL);
  if (a == c)
    {
      a = 0;
      if ((c = read(fd, buffer, MEM_SIZE)) <= 0)
	return (NULL);
    }
  b = 0;
  while (b < MEM_SIZE && a < c && buffer[a] != '\n')
    str[b++] = buffer[a++];
  str[b] = '\0';
  if (buffer[a] == '\n')
    a++;
  else
    str = my_strcat(str, get_next_line(fd));
  return (str);
}

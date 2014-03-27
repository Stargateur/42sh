/*
** get_next_line.c for get_next_line.c in /home//rendu/CPE_2013_getnextline
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Nov 18 17:05:38 2013 Pierrick Gicquelais
** Last update Thu Mar 27 14:40:37 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	"shell.h"

static char	*re_alloc(char *str)
{
  char		*str2;
  int		i;

  i = 0;
  if ((str2 = malloc((strlen(str) + 2) * sizeof(char))) == NULL)
    {
      printf("Error with a memory allocation\n");
      exit(EXIT_FAILURE);
    }
  while (str[i] != '\0')
    {
      str2[i] = str[i];
      i++;
    }
  str2[i + 1] = '\0';
  free(str);
  return (str2);
}

char		*get_next_line(const int fd)
{
  int		i;
  int		size;
  static char	buf[BUF_SIZE];
  char		*str;

  i = 0;
  size = 0;
  if ((str = malloc(sizeof(char))) == NULL)
    {
      printf("Error with a memory allocation\n");
      exit(EXIT_FAILURE);
    }
  str[0] = '\0';
  while ((size = read(fd, buf, BUF_SIZE)) > 0 && buf[0] != '\n')
    {
      str = re_alloc(str);
      str[i++] = buf[0];
    }
  if (size == 0 && i == 0)
    return (NULL);
  return (str);
}

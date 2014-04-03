/*
** get_next_line.c for get next line in /home/marsil_g/Documents/CPE/GetNext
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Thu Dec 19 10:48:14 2013 Gabriele Marsili
** Last update Sat Mar  8 16:09:24 2014 marsil_g
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

void		empty_buffer(char *buffer)
{
  int		i;

  i = 0;
  while (i <= BUFFER)
    {
      buffer[i] = 0;
      i++;
    }
}

void		verif_buff(char *buffer, char *str, int *i, int *j)
{
  *j = 0;
  while (*i > 0 && buffer[*i] && buffer[*i] != '\n')
    {
      str[*j] = buffer[*i];
      (*i)++;
      (*j)++;
    }
  if (buffer[*i] != '\n')
    {
      empty_buffer(buffer);
      *i = 0;
    }
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFFER];
  char		*str;
  static int	i;
  int		j;
  int		rd;

  if ((str = malloc(READ_MAX * sizeof(*str))) == NULL)
    my_err_mall("get_next_line");
  verif_buff(buffer, str, &i, &j);
  rd = 1;
  while (j < READ_MAX && buffer[i] != '\n' && rd)
    {
      rd = read(fd, buffer, BUFFER - 1);
      buffer[rd] = '\0';
      i = 0;
      while (buffer[i] && j < READ_MAX && buffer[i] != '\n')
	str[j++] = buffer[i++];
      if (!buffer[i])
	empty_buffer(buffer);
    }
  if (buffer[i] == '\n')
    i++;
  if (!rd && !i)
    return (0);
  str[j] = 0;
  return (str);
}

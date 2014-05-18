/*
** my_fputstr.c for putstr in /home/marsil_g/rendu/crypt/functions
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Wed May 14 09:29:43 2014 Gabriele Marsili
** Last update Wed May 14 10:12:03 2014 rousse_3
*/

#include	<stdlib.h>
#include	"includes.h"

int		my_fputstr(const int fd, char *str)
{
  int		i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i])
    my_fputchar(fd, str[i]);
  return (0);
}

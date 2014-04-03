/*
** my_lib2.c for my_lib2 in /home/costa_b/rendu/PSU_2013_minishell2
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Feb 20 17:25:46 2014 Kevin Costa
** Last update Fri Mar  7 18:12:38 2014 Kevin Costa
*/

#include        <stdlib.h>
#include	"my.h"

int		my_strlen(char *str)
{
  int		a;

  a = 0;
  while (str[a])
    a++;
  return (a);
}

char		*my_strcpy(char *dest, char *src)
{
  int		a;

  a = 0;
  while (src[a])
    {
      dest[a] = src[a];
      a++;
    }
  dest[a] = 0;
  return (dest);
}

int		my_strcmp(char *s1, char *s2)
{
  int	        a;

  a = 0;
  while (s1[a] == s2[a] && s1[a])
    a++;
  return (s1[a] - s2[a]);
}

char		*my_strtabcpy(char **dest, char **src)
{
  int		a;

  a = 0;
  while (src[a])
    {
      dest[a] = src[a];
      a++;
    }
  dest[a] = 0;
  return (*dest);
}

void		my_put_error(char *str)
{
  while (*str)
    my_putchar(*str++);
  exit(-1);
}

/*
** my_str.c for 42sh in /home/makusa_n/depot_git/PSU_2013_42sh/my_conf
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Fri May 16 15:54:37 2014 Nayden Makusa
** Last update Mon May 19 10:02:53 2014 Nayden Makusa
*/

#include	<unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *str)
{
  int		i;

  i = -1;
  if (str == NULL)
    return (1);
  while (str[++i] != '\0')
    my_putchar(str[i]);
  return (0);
}

int		my_strcmp_maj(char *s1, char *s2)
{
  int		a;

  a = 0;
  while (s1[a] != '\0' || s2[a] != '\0')
    {
      if (s1[a] != s2[a] && s1[a] != (s2[a] - 32))
	return (1);
      a++;
    }
  return (0);
}

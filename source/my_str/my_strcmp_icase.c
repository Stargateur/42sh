/*
** my_strcmp_icase.c for my_strcmp_icase in /home/plasko_a/rendu/epic_js_fantasy/source/my_server/my_parse
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat May 10 20:52:01 2014 Antoine Plaskowski
** Last update Sat May 10 20:59:40 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

static int	my_cmp_icase(char a, char b)
{
  if (a >= 'A' && a <= 'Z')
    a = a -'A' + 'a';
  if (b >= 'A' && b <= 'Z')
    b = b -'A' + 'a';
  return (a - b);
}

int		my_strcmp_icase(const char *str_1, const char *str_2)
{
  int		i;
  int		ret;

  if (str_1 == NULL || str_2 == NULL)
    return (1);
  i = 0;
  while ((ret = my_cmp_icase(str_1[i], str_2[i])) == 0 && str_1[i] != '\0')
    i++;
  return (ret);
}

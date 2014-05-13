/*
** my_nbr_to_str.c for my_nbr_to_str in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_str
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Tue May 13 18:05:45 2014 Antoine Plaskowski
** Last update Tue May 13 18:05:54 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_typedef.h"

static int	my_size_nbr(int nbr)
{
  t_uint	i;

  if (nbr < 0)
    i = 2;
  else
    i = 1;
  while ((nbr /= 10))
    i++;
  return (i);
}

static void	my_put_nbr_to_str(char *str, int nbr, t_uint i)
{
  if (nbr / 10)
    my_put_nbr_to_str(str, nbr / 10, i - 1);
  else if (nbr < 0)
    str[i - 1] = '-';
  if ((nbr %= 10) < 0)
    nbr *= -1;
  str[i] = nbr + '0';
}

char		*my_nbr_to_str(int nbr)
{
  char		*str;
  t_uint	i;

  i = my_size_nbr(nbr);
  if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  str[i--] = '\0';
  my_put_nbr_to_str(str, nbr, i);
  return (str);
}

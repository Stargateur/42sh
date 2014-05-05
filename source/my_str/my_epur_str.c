/*
** my_epur_str.c for my_epur_str in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar 10 18:23:06 2014 Antoine Plaskowski
** Last update Fri May  2 03:24:52 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

static t_uint	my_len_epur_str(char *str)
{
  t_uint	i;

  i = 0;
  while (*str != '\0')
    {
      while (*str != ' ' && *str != '\t' && *str != '\0')
	{
	  i++;
	  str++;
	}
      while (*str == ' ' || *str == '\t')
	str++;
      if (str != '\0')
	i++;
    }
  return (sizeof(char) * (i + 1));
}

char		*my_epur_str(char *str)
{
  char		*epur;
  t_uint	i;

  if (str == NULL)
    return (NULL);
  while (*str == ' ' || *str == '\t')
    str++;
  if ((epur = my_calloc(my_len_epur_str(str))) == NULL)
    return (NULL);
  i = 0;
  while (*str != '\0')
    {
      while (*str != ' ' && *str != '\t' && *str != '\0')
	epur[i++] = *str++;
      while (*str == ' ' || *str == '\t')
	str++;
      if (*str != '\0')
	epur[i++] = ' ';
    }
  epur[i] = '\0';
  return (epur);
}

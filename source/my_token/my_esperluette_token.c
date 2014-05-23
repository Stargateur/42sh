/*
** my_esperluette_token.c for my_esperluette_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 18:16:42 2014 Antoine Plaskowski
** Last update Fri May 23 10:43:55 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_token.h"

t_token		*my_esperluette_token(char *str, int *i)
{
  if (str == NULL || i == NULL)
    return (NULL);
  if (str[(*i)++] != '&')
    return (NULL);
  if (str[*i] == '&')
    return (my_and_token(str, i));
  (*i)--;
  return (NULL);
}

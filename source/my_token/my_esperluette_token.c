/*
** my_esperluette_token.c for my_esperluette_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 18:16:42 2014 Antoine Plaskowski
** Last update Sun May 25 20:53:09 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"

t_token		*my_esperluette_token(char *str, int *i)
{
  t_token	*token;

  if (str == NULL || i == NULL)
    return (NULL);
  if (str[(*i)++] != '&')
    return (NULL);
  if (str[*i] == '&')
    return (my_and_token(str, i));
  if ((token = my_new_token()) == NULL)
    return (NULL);
  token->type = O_ESPE;
  token->priority = P_O_ESPE;
  return (token);
}

/*
** my_and_token.c for my_and_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed May  7 19:05:27 2014 Antoine Plaskowski
** Last update Fri May  9 11:20:19 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"

t_token		*my_and_token(char *str, int *i)
{
  t_token	*token;

  if (str == NULL || i == NULL)
    return (NULL);
  if (str[(*i)++] != '&')
    return (NULL);
  if ((token = my_new_token()) == NULL)
    return (NULL);
  token->type = O_AND;
  token->priority = P_O_AND;
  return (token);
}

/*
** my_pipe_token.c for my_pipe_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 18:16:42 2014 Antoine Plaskowski
** Last update Fri May  9 11:23:03 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"

t_token		*my_pipe_token(char *str, int *i)
{
  t_token	*token;

  if (str == NULL || i == NULL)
    return (NULL);
  if (str[(*i)++] != '|')
    return (NULL);
  if (str[*i] == '|')
    return (my_or_token(str, i));
  if ((token = my_new_token()) == NULL)
    return (NULL);
  token->type = O_PIPE;
  token->priority = P_O_PIPE;
  return (token);
}

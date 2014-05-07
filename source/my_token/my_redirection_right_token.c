/*
** my_redirection_right_token.c for ùy_redirection_right_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed May  7 19:03:47 2014 Antoine Plaskowski
** Last update Wed May  7 19:10:51 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"

t_token		*my_redirection_right_token(char *str, int *i)
{
  t_token	*token;

  if (str == NULL || i == NULL)
    return (NULL);
  if (str[(*i)++] != '>')
    return (NULL);
  if (str[*i] != '>')
    return (my_redirection_double_right_token(str, i));
  if ((token = my_new_token()) == NULL)
    return (NULL);
  token->type = O_RRIGHT;
  return (token);
}

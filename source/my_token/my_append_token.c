/*
** my_append_token.c for my_append_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed May  7 17:10:47 2014 Antoine Plaskowski
** Last update Wed May  7 17:32:46 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

t_token		*my_append_token(t_token *old, char *attribute, int type)
{
  t_token	*token;

  if ((token = malloc(sizeof(t_token))) == NULL)
    return (NULL);
  if ((old = my_last_token(old)) != NULL)
    old->next = token;
  token->type = type;
  token->attribute = attribute;
  token->prev = old;
  token->next = NULL;
  return (token);
}

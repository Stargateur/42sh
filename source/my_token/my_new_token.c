/*
** my_new_token.c for my_new_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 18:21:06 2014 Antoine Plaskowski
** Last update Wed May 14 00:10:01 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

t_token		*my_new_token(void)
{
  t_token	*token;

  if ((token = my_malloc(sizeof(t_token))) == NULL)
    return (NULL);
  token->prev = NULL;
  token->next = NULL;
  token->attribute = NULL;
  token->type = NONE;
  token->priority = P_NONE;
  return (token);
}

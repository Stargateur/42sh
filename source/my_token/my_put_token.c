/*
** my_put_token.c for my_put_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 17:57:00 2014 Antoine Plaskowski
** Last update Wed May  7 17:57:56 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

t_token		*my_put_token(t_token *old, t_token *token)
{
  if ((old = my_last_token(old)) != NULL)
    old->next = token;
  if (token != NULL)
    {
      token->prev = old;
      token->next = NULL;
    }
  return (token);
}

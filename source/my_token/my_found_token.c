/*
** my_found_token.c for my_found_token in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat May 17 19:17:52 2014 Antoine Plaskowski
** Last update Sat May 17 19:19:55 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"

t_token		*my_found_token(t_token *token, t_type type)
{
  token = my_first_token(token);
  while (token != NULL && token->type != type)
    token = token->next;
  return (token);
}

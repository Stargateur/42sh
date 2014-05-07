/*
** my_first_token.c for my_first_token in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 16:54:55 2014 Antoine Plaskowski
** Last update Wed May  7 17:38:00 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"

t_token		*my_first_token(t_token *token)
{
  if (token != NULL)
    while (token->prev != NULL)
      token = token->prev;
  return (token);
}

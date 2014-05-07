/*
** my_last_token.c for my_last_token in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 16:54:55 2014 Antoine Plaskowski
** Last update Wed May  7 17:38:07 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"

t_token		*my_last_token(t_token *token)
{
  if (token != NULL)
    while (token->next != NULL)
      token = token->next;
  return (token);
}

/*
** my_free_token.c for my_free_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed May  7 17:25:15 2014 Antoine Plaskowski
** Last update Sun May 25 14:46:57 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

void		my_free_token(t_token *token)
{
  if (token != NULL)
    {
      free(token->attribute);
      free(token);
    }
}

void		my_free_all_token(t_token *token)
{
  t_token	*tmp;

  token = my_first_token(token);
  while (token != NULL)
    {
      tmp = token;
      token = token->next;
      my_free_token(tmp);
    }
}

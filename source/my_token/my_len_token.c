/*
** my_len_token.c for my_len_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 19:30:10 2014 Antoine Plaskowski
** Last update Wed May  7 19:32:46 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_typedef.h"

t_uint		my_len_token(t_token *token)
{
  t_uint	i;

  token = my_first_token(token);
  i = 0;
  while (token != NULL)
    {
      i++;
      token = token->next;
    }
  return (i);
}

/*
** my_aff_token.c for my_aff_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed May  7 17:29:01 2014 Antoine Plaskowski
** Last update Wed May  7 17:38:24 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

int		my_aff_token(t_token *token, const int fd)
{
  if (token != NULL)
    {
      my_putstr("type : ", fd);
      my_putnbr(token->type, fd);
      my_putstr("\nattribute : ", fd);
      my_putstr(token->attribute, fd);
      my_putchar('\n', fd);
    }
  return (0);
}

int		my_aff_all_token(t_token *token, const int fd)
{
  token = my_first_token(token);
  while (token != NULL)
    {
      my_aff_token(token, fd);
      token = token->next;
    }
  return (0);
}

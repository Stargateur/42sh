/*
** my_aff_token.c for my_aff_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed May  7 17:29:01 2014 Antoine Plaskowski
** Last update Fri May  9 13:30:33 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

static int	my_aff_type_token(const int type, const int fd)
{
  if (type == WORD)
    my_putstr("WORD", fd);
  else if (type == O_OR)
    my_putstr("OR", fd);
  else if (type == O_AND)
    my_putstr("AND", fd);
  else if (type == O_COMMA)
    my_putstr("COMA", fd);
  else if (type == O_PIPE)
    my_putstr("PIPE", fd);
  else if (type == O_RLEFT)
    my_putstr("RLEFT", fd);
  else if (type == O_RRIGHT)
    my_putstr("RRIGHT", fd);
  else if (type == O_RDLEFT)
    my_putstr("RDLEFT", fd);
  else if (type == O_RDRIGHT)
    my_putstr("RDRIGHT", fd);
  else if (type == NONE)
    my_putstr("NONE", fd);
  else
    return (1);
  return (0);
}

int		my_aff_token(t_token *token, const int fd)
{
  if (token != NULL)
    {
      my_putstr("type : ", fd);
      my_aff_type_token(token->type, fd);
      my_putstr("\npriority : ", fd);
      my_putnbr(token->priority, fd);
      if (token->attribute != NULL)
	{
	  my_putstr("\nattribute : ", fd);
	  my_putstr(token->attribute, fd);
	}
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

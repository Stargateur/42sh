/*
** my_word_token.c for my_word_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 19:12:31 2014 Antoine Plaskowski
** Last update Sun May 18 23:18:50 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

static t_token	*my_cpy_word(char *str, int *i, int n)
{
  t_token	*token;

  if ((token = my_new_token()) == NULL)
    return (NULL);
  token->type = WORD;
  token->priority = P_WORD;
  if ((token->attribute = my_strndup(str + *i, n)) == NULL)
    return (NULL);
  *i += n;
  return (token);
}

t_token		*my_word_token(char *str, int *i)
{
  int		n;

  if (str == NULL || i == NULL)
    return (NULL);
  n = 0;
  while (str[*i + n] != '\0')
    {
      if (my_char_in_str(str[*i + n], TYPE) != -1)
	return (my_cpy_word(str, i, n));
      if (my_char_in_str(str[*i + n], SEP) != -1)
	return (my_cpy_word(str, i, n));
      n++;
    }
  return (my_cpy_word(str, i, n));
}

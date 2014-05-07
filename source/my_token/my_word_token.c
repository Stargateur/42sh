/*
** my_word_token.c for my_word_token in /home/plasko_a/rendu/PSU_2013_42sh/source/my_token
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 19:12:31 2014 Antoine Plaskowski
** Last update Wed May  7 19:28:23 2014 Antoine Plaskowski
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
  if ((token->attribute = my_strndup(str + *i, n)) == NULL)
    return (NULL);
  *i += n;
  return (token);
}

t_token		*my_word_token(char *str, int *i)
{
  static char	*tab = TOKEN;
  int		j;
  int		n;

  if (str == NULL || i == NULL)
    return (NULL);
  n = 0;
  while (str[*i + n] != '\0')
    {
      j = 0;
      while (tab[j] != '\0')
	{
	  if (tab[j] == str[*i + n])
	    return (my_cpy_word(str, i, n));
	  j++;
	}
      n++;
    }
  return (my_cpy_word(str, i, n));
}

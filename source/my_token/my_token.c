/*
** my_token.c for my_token in /home/plasko_a/rendu/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 15:13:19 2014 Antoine Plaskowski
** Last update Sun May 18 22:35:54 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

static t_token	*(*const g_fct_token[])(char *str, int *i) =
{
  &my_pipe_token,
  &my_esperluette_token,
  &my_comma_token,
  &my_redirection_left_token,
  &my_redirection_right_token,
  NULL
};

static t_token	*my_check_char(char *str, int *i)
{
  int		j;

  while (my_char_in_str(str[*i], SEPARATOR) != -1)
    (*i)++;
  if ((j = my_char_in_str(str[*i], TOKEN)) != -1)
    return (g_fct_token[j](str, i));
  else if (str[*i] != '\0')
    return (my_word_token(str, i));
  return (NULL);
}

t_token		*my_token(char *str)
{
  t_token	*token;
  t_token	*tmp;
  int		i;

  if (str == NULL)
    return (NULL);
  token = NULL;
  i = 0;
  while ((tmp = my_check_char(str, &i)) != NULL)
    if ((token = my_put_token(token, tmp)) == NULL)
      return (NULL);
  if (str[i] != '\0')
    {
      my_free_all_token(token);
      return (my_put_error_null("syntax error\n"));
    }
  return (my_first_token(token));
}

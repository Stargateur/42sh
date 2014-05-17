/*
** my_token_word_to_tab.c for my_token_word_to_tab in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 18:43:59 2014 Antoine Plaskowski
** Last update Sat May 17 18:55:10 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

static t_uint	my_len_token_word(t_token *token)
{
  t_uint	i;

  i = 1;
  while (token != NULL)
    {
      if (token->type == WORD)
	i++;
      else
	token = token->next;
      if (token != NULL)
	token = token->next;
    }
  return (sizeof(char *) * i);
}

char		**my_token_word_to_tab(t_token *token)
{
  char		**tab;
  t_uint	i;

  if ((tab = my_malloc(my_len_token_word(token))) == NULL)
    return (NULL);
  i = 0;
  while (token != NULL)
    {
      if (token->type == WORD)
	{
	  if ((tab[i++] = my_strdup(token->attribute)) == NULL)
	    return (NULL);
	}
      else
	token = token->next;
      if (token != NULL)
	token = token->next;
    }
  tab[i] = NULL;
  return (tab);
}

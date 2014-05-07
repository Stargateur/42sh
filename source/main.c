/*
** main.c for main in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 14:47:16 2014 Antoine Plaskowski
** Last update Wed May  7 00:30:07 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

void		my_parsing(t_token **, char *);
void		check_token(t_token **, char);
t_token		*append_list(t_token *, int);
void		token_aff(t_token *);
void		token_free(t_token *);

int		main(int argc, char **argv)
{
  t_token	*token;
  char		*str;

  (void)argc;
  (void)argv;
  while ((str = my_get_next_line(0)) != NULL)
    {
      token = NULL;
      my_parsing(&token, str);
      token_aff(token);
      token_free(token);
      free(str);
    }
  return (0);
}

void		my_parsing(t_token **token, char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      check_token(token, str[i]);
      i++;
    }
}

void		check_token(t_token **token, char c)
{
  if (c == '|')
    *token = append_list(*token, PIPE);
  else if (c == '>')
    *token = append_list(*token, R_R);
  else if (c == '<')
    *token = append_list(*token, R_L);
  else if (c == ';')
    *token = append_list(*token, COMA);
  else
    *token = append_list(*token, WORD);
}

t_token		*append_list(t_token *token, int nbr)
{
  t_token	*new;
  t_token	*tmp;

  if ((new = malloc(sizeof(t_token))) == NULL)
    return 0;
  new->tok = nbr;
  new->next = NULL;
  if (token == NULL)
    return (new);
  tmp = token;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (token);
}

void		token_aff(t_token *token)
{
  t_token	*tmp;
  int		i;

  i = 1;
  tmp = token;
  while (tmp)
    {
      printf("Char: %d -> ", i);
      if (tmp->tok == PIPE)
	printf("Il y a un Pipe !\n");
      else if (tmp->tok == R_R)
	printf("Il y a une Simple redir Droite !\n");
      else if (tmp->tok == R_L)
	printf("Il y a une Simple redir Gauche !\n");
      else if (tmp->tok == COMA)
	printf("Il y a un Point virgule !\n");
      else if (tmp->tok == WORD)
	printf("Il y a une Commande !\n");
      else
	printf("Charactère inconnu au n°%d\n", i);
      tmp = tmp->next;
      i++;
    }
}

void		token_free(t_token *token)
{
  t_token	*tmp;
  t_token	*tmp2;

  tmp = token;
  while (tmp)
    {
      tmp2 = tmp->next;
      free(tmp);
      tmp = tmp2;
    }
}

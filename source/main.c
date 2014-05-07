/*
** main.c for main in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 14:47:16 2014 Antoine Plaskowski
** Last update Wed May  7 17:43:43 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

t_token		*check_token(t_token *token, char c)
{
  if (c == '|')
    token = my_append_token(token, NULL, PIPE);
  else if (c == '>')
    token = my_append_token(token, NULL, R_R);
  else if (c == '<')
    token = my_append_token(token, NULL, R_L);
  else if (c == ';')
    token = my_append_token(token, NULL, COMA);
  else
    token = my_append_token(token, NULL, WORD);
  return (token);
}

t_token		*my_parsing(char *str)
{
  t_token	*token;

  token = NULL;
  while (*str != '\0')
    token = check_token(token, *str++);
  return (token);
}

int		main(int argc, char **argv)
{
  t_token	*token;
  char		*str;

  (void)argc;
  (void)argv;
  while ((str = my_get_next_line(0)) != NULL)
    {
      token = my_parsing(str);
      my_aff_all_token(token, 1);
      my_free_all_token(token);
      free(str);
    }
  return (0);
}

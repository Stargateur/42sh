/*
** my_search_redir.c for my_search_redir in /home/plasko_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar  9 12:26:54 2014 Antoine Plaskowski
** Last update Sun Mar  9 16:32:11 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_struct_cmd.h"
#include	"my_str.h"

static char	*my_name_file(char *input)
{
  char		*name;
  int		i;

  while (*input == '<' || *input == '>' || *input == ' ' || *input == '\t')
    input++;
  i = 0;
  while (input[i] != ';' && input[i] != '|' && input[i] != '<' &&
	 input[i] != '>' && input[i] != ' ' && input[i] != '\t' &&
	 input[i] != '\0')
    i++;
  if ((name = my_malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (*input != ';' && *input != '|' && *input != '<' &&
	 *input != '>' && *input != ' ' && *input != '\t' &&
	 *input != '\0')
    name[i++] = *input++;
  name[i] = '\0';
  return (name);
}

int		my_search_redir(t_cmd *cmd, char *input)
{
  char		*tmp;

  if (cmd == NULL || input == NULL)
    return (1);
  while (*input != '\0')
    if (*input == '<' || *input == '>')
      {
	if ((tmp = my_name_file(input)) == NULL)
	  return (1);
	if (my_strncmp("<<", input, 2) == 0)
	  cmd->dleft = tmp;
	else if (my_strncmp("<", input, 1) == 0)
	  cmd->left = tmp;
	else if (my_strncmp(">>", input, 2) == 0)
	  cmd->dright = tmp;
	else if (my_strncmp(">", input, 1) == 0)
	  cmd->right = tmp;
	while (*input == '<' || *input == '>')
	  input++;
      }
    else if (*input == '|' || *input == ';')
      return (0);
    else
      input++;
  return (0);
}

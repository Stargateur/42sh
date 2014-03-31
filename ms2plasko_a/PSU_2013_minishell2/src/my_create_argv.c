/*
** my_create_argv.c for my_create_argv in /home/plasko_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar  9 10:05:39 2014 Antoine Plaskowski
** Last update Sun Mar  9 21:08:27 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

static int	my_jump_word(char **input)
{
  if (**input == '<' || **input == '>')
    {
      while (**input == '<' || **input == '>')
	(*input)++;
      while (**input == ' ' || **input == '\t')
	(*input)++;
      while (**input != ';' && **input != '|' && **input != '<' &&
	     **input != '>' && **input != ' ' && **input != '\t' &&
	     **input != '\0')
	(*input)++;
      return (0);
    }
  return (1);
}

static int	my_len_argv(char *input)
{
  int		i;

  i = 0;
  while (*input != ';' && *input != '|' && *input != '\0')
    {
      while (*input == ' ' || *input == '\t')
	input++;
      if (*input == ';' || *input == '|' || *input == '\0')
	return (i + 1);
      if (my_jump_word(&input))
	i++;
      while (*input != ';' && *input != '|' && *input != '<' &&
	     *input != '>' && *input != ' ' && *input != '\t' &&
	     *input != '\0')
	input++;
    }
  return (i + 1);
}

static int	my_len_word(char *input)
{
  int		i;

  i = 0;
  while (input[i] != ';' && input[i] != '|' && input[i] != '<' &&
	 input[i] != '>' && input[i] != ' ' && input[i] != '\t' &&
	 input[i] != '\0')
    i++;
  return (i + 1);
}

static int	my_cpy_word(char **input, char **tab, int *i)
{
  int		j;

  if (**input != ';' && **input != '|' && **input != '\0')
    {
      if (!(tab[*i] = my_malloc(sizeof(char) * my_len_word(*input))))
	return (1);
      j = 0;
      while (**input != ';' && **input != '|' && **input != '<' &&
	     **input != '>' && **input != ' ' && **input != '\t' &&
	     **input != '\0')
	tab[*i][j++] = *(*input)++;
      tab[(*i)++][j] = '\0';
    }
  return (0);
}

char		**my_create_argv(char *input)
{
  char		**tab;
  int		i;

  if (!input || !(tab = my_malloc(sizeof(char *) * my_len_argv(input))))
    return (NULL);
  i = 0;
  while (*input != ';' && *input != '|' && *input != '\0')
    {
      while (*input == ' ' || *input == '\t')
	input++;
      if (my_jump_word(&input))
	{
	  if (my_cpy_word(&input, tab, &i))
	    return (NULL);
	}
    }
  tab[i] = NULL;
  return (tab);
}

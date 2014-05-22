/*
** my_builtin.c for my_builtin in /home/plasko_a/programation/epitech/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May 19 02:50:18 2014 Antoine Plaskowski
** Last update Thu May 22 16:41:52 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_shell.h"
#include	"my_exec.h"
#include	"my_env.h"
#include	"my_str.h"

static t_fbuil	g_builtin[] =
  {
    {&my_exit, "exit"},
    {&my_env, "env"},
    {&my_setenv, "setenv"},
    {&my_unsetenv, "unsetenv"},
    {NULL, NULL}
  };

int		my_check_builtin(t_token *token)
{
  int		i;

  token = my_first_token(token);
  while (token != NULL && token->type != WORD)
    token = token->next;
  if (token == NULL)
    return (-1);
  i = 0;
  while (g_builtin[i].fct != NULL)
    {
      if (my_strcmp(g_builtin[i].name, token->attribute) == 0)
	return (i);
      i++;
    }
  return (-1);
}

int		my_builtin(t_shell *shell, t_token *token, t_fd *fd)
{
  int		i;
  char		**tab;
  int		ret;

  if ((i = my_check_builtin(token)) == -1)
    return (1);
  if ((tab = my_token_word_to_tab(token)) == NULL)
    return (1);
  ret = g_builtin[i].fct(shell, fd, tab);
  my_free_tab(tab);
  my_close_fd(fd);
  return (ret);
}

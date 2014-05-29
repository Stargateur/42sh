/*
** main.c for main in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 14:47:16 2014 Antoine Plaskowski
** Last update Thu May 29 17:39:50 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	"my_shell.h"
#include	"my_token.h"
#include	"my_btree.h"
#include	"my_str.h"
#include	"my_exec.h"
#include	"my_env.h"
#include	"my_history.h"

static void	my_put_prompt(t_env *env)
{
  env = my_first_env(env);
  while (env && my_strcmp(env->name, "PS1"))
    env = env->next;
  if (env == NULL)
    my_putstr("42sh> ", 1);
  else
    my_putstr(env->value, 1);
}

static char	*my_promt(t_shell *shell)
{
  char		*str;
  char		*ret;

  if (isatty(0))
    my_put_prompt(shell->env);
  str = my_get_next_line(0);
  shell->history = my_history(shell->history, str);
  if ((ret = check_line(shell->history, str)) == NULL)
    return (str);
  free(str);
  return (ret);
}

static t_btree	*my_parse(char *str)
{
  t_token	*token;
  t_btree	*btree;

  if ((token = my_token(str)) == NULL)
    return (NULL);
  if ((btree = my_btree(token)) == NULL)
    return (my_put_error_null("Syntax error\n"));
  if (my_check_btree(btree))
    {
      my_free_all_btree(btree);
      return (my_put_error_null("Ambiguous redirect\n"));
    }
  return (btree);
}

static int	my_ignore_signal(void)
{
  if (isatty(0))
    {
      if ((signal(SIGINT, SIG_IGN)) == SIG_ERR)
	my_putstr("can't set ignore sigint\n", 2);
      if ((signal(SIGTSTP, SIG_IGN)) == SIG_ERR)
	my_putstr("can't set ignore sigstop\n", 2);
    }
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  t_shell	shell;
  t_btree	*btree;
  char		*str;
  int		ret;

  (void)argc;
  (void)argv;
  my_ignore_signal();
  my_shell(&shell, env);
  while (shell.exit == 0 && (str = my_promt(&shell)) != NULL)
    {
      if ((btree = my_parse(str)) != NULL)
	if ((ret = my_exec(btree, &shell)))
	  shell.exit_value = ret;
      my_free_all_btree(btree);
      free(str);
    }
  my_free_all_env(shell.env);
  my_free_all_history(shell.history);
  if (shell.exit_print && isatty(0))
    my_putstr("exit\n", 1);
  return (shell.exit_value);
}

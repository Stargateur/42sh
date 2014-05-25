/*
** main.c for main in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 14:47:16 2014 Antoine Plaskowski
** Last update Sun May 25 14:30:16 2014 Antoine Plaskowski
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

static char	*my_promt(void)
{
  if (isatty(0))
    my_putstr("42sh> ", 1);
  return (my_get_next_line(0));
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

int		my_ignore_signal(void)
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

  (void)argc;
  (void)argv;
  my_ignore_signal();
  my_shell(&shell, env);
  while (shell.exit == 0 && (str = my_promt()) != NULL)
    {
      if ((btree = my_parse(str)) != NULL)
	my_exec(btree, &shell);
      my_free_all_btree(btree);
      free(str);
    }
  my_free_all_env(shell.env);
  if (shell.exit_print && isatty(0))
    my_putstr("exit\n", 1);
  return (shell.exit_value);
}

/*
** main.c for main in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 14:47:16 2014 Antoine Plaskowski
** Last update Mon May 19 03:21:59 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_token.h"
#include	"my_btree.h"
#include	"my_str.h"
#include	"my_exec.h"
#include	"my_env.h"

static char	*my_promt(void)
{
  my_putstr("42sh> ", 1);
  return (my_get_next_line(0));
}

static t_btree	*my_shining_force(char *str)
{
  t_token	*token;
  t_btree	*btree;

  if ((token = my_token(str)) == NULL)
    return (NULL);
  if ((btree = my_btree(token)) == NULL)
    return (my_put_error_null("gramaire error\n"));
  if (my_check_btree(btree))
    {
      my_free_all_btree(btree);
      return (my_put_error_null("message will come\n"));
    }
  return (btree);
}

int		main(int argc, char **argv, char **env)
{
  t_shell	shell;
  t_btree	*btree;
  char		*str;

  (void)argc;
  (void)argv;
  my_shell(&shell, env);
  while (shell.exit == 0 && (str = my_promt()) != NULL)
    {
      if ((btree = my_shining_force(str)) != NULL)
	{
	  my_exec(btree, &shell);
	  my_free_all_btree(btree);
	}
      free(str);
    }
  my_putstr("exit\n", 1);
  return (shell.exit_value);
}

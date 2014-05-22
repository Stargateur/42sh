/*
** main.c for 42sjh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 22 13:23:57 2014 Pierrick Gicquelais
** Last update Thu May 22 16:10:55 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_env.h"
#include	"my_str.h"

int		main(int argc, char **argv, char **envp)
{
  t_shell	*shell;
  char		**tab;
  char		*s;
  t_fd		*fd;

  (void)argc;
  (void)argv;
  (void)fd;
  shell = malloc(sizeof(t_shell));
  shell->env = my_copy_env(envp);
  while ((s = my_get_next_line(0)) != NULL)
    {
      tab = my_str_to_tab(s, " ");
      if (my_strcmp(tab[0], "env") == 0)
	my_env(shell, fd, tab);
      else if (my_strcmp(tab[0], "setenv") == 0)
	my_setenv(shell, fd, tab);
      else if (my_strcmp(tab[0], "unsetenv") == 0)
	my_unsetenv(shell, fd, tab);
      else
	my_putstr("Command env not found\n", 1);
      my_free_tab(tab);
    }
  my_aff_all_env(shell->env, 1);
  my_free_all_env(shell->env);
  return (0);
}

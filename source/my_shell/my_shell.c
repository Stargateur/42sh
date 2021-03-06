/*
** my_shell.c for my_shell in /home/plasko_a/programation/epitech/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 22:13:17 2014 Antoine Plaskowski
** Last update Thu May 29 17:51:24 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_edit.h"

int		my_shell(t_shell *shell, char **env)
{
  if (shell == NULL)
    return (1);
  shell->env = my_copy_env(env);
  shell->env = my_put_ps1(shell->env);
  shell->term = term_init(shell->env);
  shell->history = NULL;
  shell->cd = NULL;
  shell->pid = NULL;
  shell->exit = 0;
  shell->exit_value = 0;
  shell->exit_print = 1;
  return (0);
}

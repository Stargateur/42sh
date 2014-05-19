/*
** my_shell.c for my_shell in /home/plasko_a/programation/epitech/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 22:13:17 2014 Antoine Plaskowski
** Last update Sun May 18 22:15:53 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_shell.h"

int		my_shell(t_shell *shell, char **env)
{
  if (shell == NULL)
    return (1);
  shell->env = my_env(env);
  shell->exit = 0;
  shell->exit_value = 0;
  return (0);
}
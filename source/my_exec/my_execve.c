/*
** my_execve.c for my_execve in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed May 14 00:42:32 2014 Antoine Plaskowski
** Last update Sun May 25 14:04:41 2014 Antoine Plaskowski
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<signal.h>
#include	<unistd.h>
#include	"my_shell.h"
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

static int	my_micro_management(char **tab, char **env, char *exe)
{
  if (signal(SIGINT, SIG_DFL) == SIG_ERR)
    my_putstr("error signal\n", 2);
  if (signal(SIGTSTP, SIG_DFL) == SIG_ERR)
    my_putstr("error signal\n", 2);
  if (exe != NULL)
    if (execve(exe, tab, env))
      my_putstr("fail exeve\n", 2);
  free(exe);
  return (1);
}

int		my_execve(t_btree *btree, t_fd *fd, t_shell *shell)
{
  char		**tab;
  char		**env;

  if (shell == NULL)
    return (1);
  env = my_env_to_tab(shell->env);
  my_dup_fd(fd);
  if (btree != NULL)
    if ((tab = my_token_word_to_tab(btree->token)) != NULL)
      {
	if (my_len_tab(tab) != 0)
	  my_micro_management(tab, env, my_found_exe(shell->env, tab[0]));
	my_free_tab(tab);
      }
  my_free_tab(env);
  shell->exit = 1;
  shell->exit_value = 1;
  shell->exit_print = 0;
  return (1);
}

/*
** my_execve.c for my_execve in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed May 14 00:42:32 2014 Antoine Plaskowski
** Last update Thu May 29 18:10:22 2014 Antoine Plaskowski
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

void		my_execve(t_btree *btree, t_fd *fd, t_shell *shell)
{
  char		**tab;
  char		**env;
  int		ret;

  ret = 1;
  my_dup_fd(fd);
  if (my_check_builtin(btree->token) != -1)
    ret = my_builtin(shell, btree->token);
  else
    if (btree != NULL && shell != NULL)
      if ((tab = my_token_word_to_tab(btree->token)) != NULL)
	{
	  env = my_env_to_tab(shell->env);
	  if (my_len_tab(tab) != 0)
	    ret = my_micro_management(tab, env,
				      my_found_exe(shell->env, tab[0]));
	  my_free_tab(tab);
	  my_free_tab(env);
	}
  exit(ret);
}

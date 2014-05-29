/*
** my_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 22 14:42:17 2014 Pierrick Gicquelais
** Last update Thu May 29 17:41:23 2014 Antoine Plaskowski
*/

#define		_POSIX_SOURCE

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	<unistd.h>
#include	"my_shell.h"
#include	"my_exec.h"
#include	"my_env.h"
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

int		my_env_exec(t_env *env, char **argv, t_shell *shell)
{
  char		**env_tab;
  int		ret;
  char		*exe;

  ret = 1;
  if (shell != NULL)
    {
      env_tab = my_env_to_tab(env);
      if (my_len_tab(argv) != 0)
	{
	  exe = my_found_exe(shell->env, argv[0]);
	  ret = my_micro_management(argv, env_tab, exe);
	}
      my_free_tab(env_tab);
    }
  exit(ret);
}

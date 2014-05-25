/*
** my_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 22 14:42:17 2014 Pierrick Gicquelais
** Last update Sun May 25 16:16:14 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_shell.h"
#include	"my_exec.h"
#include	"my_env.h"
#include	"my_str.h"

static int	check_option(t_env **env, char **argv, int *i)
{
  if (argv[*i] == NULL)
    return (1);
  if (my_strcmp(argv[*i], "-i") == 0)
    while (*env != NULL)
      *env = my_sup_env(*env, (*env)->name);
  else if (my_strcmp(argv[*i], "-u") == 0)
    {
      if (!argv[++(*i)])
	{
	  my_putstr("env: option requires an argument -- 'u'\n", 1);
	  return (1);
	}
      *env = my_sup_env(*env, argv[*i]);
    }
  else if (*argv[*i] == '-')
    {
      my_putstr("env: invalid option -- ", 1);
      my_putstr(argv[*i], 1);
      my_putchar('\n', 1);
    }
  else
    return (2);
  return (0);
}

int		my_env(t_shell *shell, t_fd *fd, char **argv)
{
  t_env		*env;
  int		ret;
  int		len;
  int		i;

  if (shell == NULL || fd == NULL || argv == NULL)
    return (1);
  env = my_cpy_env(shell->env);
  len = my_len_tab(argv);
  i = 1;
  ret = 0;
  while (i < len && (ret = check_option(&env, argv, &i)) == 0)
    i++;
  if (ret == 0)
    {
      if (fd->fd_1 != -1)
	my_aff_all_env(env, fd->fd_1);
      else
	my_aff_all_env(env, 1);
    }
  else if (ret == 2)
    ret = my_env_exec(env, my_cpy_tab(argv + i), fd, shell);
  my_free_all_env(env);
  return (ret);
}

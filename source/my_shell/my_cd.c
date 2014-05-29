/*
** my_cd.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_shell
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 23 17:37:14 2014 Pierrick Gicquelais
** Last update Thu May 29 18:20:07 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_shell.h"
#include	"my_str.h"
#include	"my_exec.h"

static int	my_old(t_env *env)
{
  t_env		*oldpwd;

  if ((oldpwd = my_found_env(env, "OLDPWD")) == NULL)
    return (my_put_error("no OLDPWD set\n"));
  return (my_chdir(oldpwd->value));
}

static int	my_home(t_env *env)
{
  t_env		*home;

  if ((home = my_found_env(env, "HOME")) == NULL)
    return (my_put_error("no HOME set\n"));
  return (my_chdir(home->value));
}

static int	my_change_env(t_shell *shell, char *buf)
{
  shell->env = my_add_env(shell->env, "OLDPWD", buf);
  if (getcwd(buf, 2048) != buf)
    return (my_put_error("fail getcwd\n"));
  shell->env = my_add_env(shell->env, "PWD", buf);
  shell->cd = my_strdup(buf);
  return (0);
}

int		my_cd(t_shell *shell,  char **argv)
{
  static char	buf[2048 + 1];
  int		len;
  int		ret;

  if (shell == NULL || argv == NULL)
    return (1);
  if ((len = my_len_tab(argv)) == 0)
    return (1);
  else if (len > 2)
    return (my_put_error("cd : too many arguments\n"));
  if (getcwd(buf, 2048) != buf)
    return (my_put_error("fail getcwd\n"));
  if (len == 1)
    ret = my_home(shell->env);
  else if (my_strcmp(argv[1], "-") == 0)
    ret = my_old(shell->env);
  else
    ret = my_chdir(argv[1]);
  if (ret != 0)
    return (1);
  return (my_change_env(shell, buf));
}

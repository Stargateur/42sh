/*
** my_cd.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_shell
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 23 17:37:14 2014 Pierrick Gicquelais
** Last update Fri May 23 18:04:35 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_shell.h"
#include	"my_str.h"

static int	my_toomany(void)
{
  my_putstr("cd: Too many arguments.\n", 1);
  return (1);
}

static int	my_plasko(char *dir)
{
  if (chdir(dir) == -1)
    {
      my_putstr("No such file or directory\n", 1);
      return (1);
    }
  return (0);
}

static int	my_old(t_shell *shell)
{
  if ((shell->env = my_found_env(shell->env, "OLDPWD")) == NULL)
    return (1);
  my_putstr(shell->env->value, 1);
  my_putchar('\n', 1);
  if ((chdir(shell->env->value)) == -1)
    return (1);
  return (0);
}

static int	my_home(t_shell *shell)
{
  if ((shell->env = my_found_env(shell->env, "HOME")) == NULL)
    return (1);
  if ((chdir(shell->env->value)) == -1)
    return (1);
  return (0);
}

int		my_cd(t_shell *shell, t_fd *fd, char **argv)
{
  char		*old;
  int		len;

  (void)fd;
  if ((old = malloc(2048 * sizeof(char))) == NULL)
    return (1);
  old = getcwd(old, 2048);
  len = my_len_tab(argv);
  if (len > 2)
    return (my_toomany());
  if (len == 1)
    return (my_home(shell));
  else if (my_strcmp(argv[1], "-") == 0)
    return (my_old(shell));
  else
    return (my_plasko(argv[1]));
}

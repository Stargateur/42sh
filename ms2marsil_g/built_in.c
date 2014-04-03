/*
** built_in.c for built_in in /home/marsil_g/Documents/PSU/PSU-MS1/Copie
**
** Made by marsil_g
** Login   <marsil_g@epitech.net>
**
** Started on  Thu Feb 27 22:35:13 2014 marsil_g
** Last update Sun Mar  9 13:37:06 2014 marsil_g
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"my.h"

int		my_exit(char **tab, char **my_env, char **pth, char *s)
{
  int		i;

  if ((my_strcmp("exit", tab[0]) == 1) && tab[0][4] == 0)
    {
      if (tab[1] == NULL)
	{
	  free_all(tab, pth, my_env);
	  free(s);
	  exit(0);
	}
      else if (tab[1] != NULL && tab[2] == NULL)
	{
	  i = my_getnbr(tab[1]);
	  free_all(tab, pth, my_env);
	  free(s);
	  exit(i);
	}
      else
	my_putstr("Error, too many arguments to exit\n");
    }
  return (0);
}

void		cd_vide(char **my_env)
{
  int		i;
  char		*str;

  i = 0;
  while (my_env[i])
    {
      if (my_strcmp("HOME=", my_env[i]) == 1)
	{
	  str = get_home(my_env[i]);
	  chdir(str);
	  return ;
	}
      else
	i++;
    }
}

int		my_cd(char **tab, char **my_env)
{
  if ((my_strcmp("cd", tab[0]) == 1) && tab[0][2] == 0 && tab[2] == NULL)
    {
      if (tab[1] && tab[1][0] != '-' && (access(tab[1], F_OK & R_OK) == -1))
	{
	  my_putstr("bash: cd: ");
	  my_putstr(tab[1]);
	  my_putstr(" No such file or directory\n");
	}
      else if (tab[1] == NULL)
	cd_vide(my_env);
      else if (tab[1] != NULL)
	chdir(tab[1]);
      return (1);
    }
  else
    return (0);
}

void		my_error(char *s)
{
  my_putstr("If it's not a typo you can use command-not-found");
  my_putstr(" to lookup the package that contains it, like this: cnf ");
  my_putstr(s);
  my_putchar('\n');
  free(s);
  exit(0);
}

pid_t		my_wait(char **tab, char **my_env, char **pth, char *s)
{
  pid_t		pid;

  pid = fork();
  waitpid(pid, 0, WSTOPPED);
  my_exit(tab, my_env, pth, s);
  return (pid);
}

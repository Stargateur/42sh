/*
** my_cd.c for my_cd in /home/plasko_a/rendu/PSU_2013_minishell1/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Dec 16 09:32:41 2013 Antoine Plaskowski
** Last update Sun Mar  9 22:33:13 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_mysh.h"
#include	"my_tool_tab.h"
#include	"my_tool_env.h"
#include	"my_pwd.h"
#include	"my_dir.h"
#include	"my_env.h"
#include	"my_str.h"

static int	my_set_pwd(t_mysh *mysh, char *old_pwd)
{
  char		*argv[4];
  char		*pwd;
  char		**tmp;

  pwd = my_pwd();
  argv[0] = "setenv";
  if ((argv[1] = my_strcat("PWD=", pwd)) == NULL)
    return (1);
  free(pwd);
  if ((argv[2] = my_strcat("OLDPWD=", old_pwd)) == NULL)
    return (1);
  free(old_pwd);
  argv[3] = NULL;
  tmp = mysh->cmd->argv;
  mysh->cmd->argv = argv;
  if (my_setenv(mysh))
    return (1);
  mysh->cmd->argv = tmp;
  free(argv[1]);
  free(argv[2]);
  return (0);
}

static int	my_cd_home(t_mysh *mysh, char *old_pwd)
{
  char		*home;

  if (mysh == NULL)
    return (1);
  if ((home = my_var_env(mysh->env, "HOME=")) == NULL)
    {
      my_putstr("HOME not set\n", 2);
      free(old_pwd);
      return (1);
    }
  if (my_chdir(home))
    {
      free(old_pwd);
      return (1);
    }
  if (my_set_pwd(mysh, old_pwd))
    return (1);
  return (0);
}

static int	my_cd_oldpwd(t_mysh *mysh, char *new_old_pwd)
{
  char		*old_pwd;

  if (mysh == NULL)
    return (1);
  if ((old_pwd = my_var_env(mysh->env, "OLDPWD=")) == NULL)
    {
      my_putstr("OLDPWD not set\n", 2);
      free(new_old_pwd);
      return (1);
    }
  if (my_chdir(old_pwd))
    {
      free(new_old_pwd);
      return (1);
    }
  if (my_set_pwd(mysh, new_old_pwd))
    return (1);
  return (0);
}

int		my_cd_normal(t_mysh *mysh, char *old_pwd)
{
  if (mysh == NULL || mysh->cmd == NULL || mysh->cmd->argv == NULL)
    return (1);
  if (my_chdir(mysh->cmd->argv[1]))
    {
      free(old_pwd);
      return (1);
    }
  if (my_set_pwd(mysh, old_pwd))
    return (1);
  return (0);
}

int		my_cd(t_mysh *mysh)
{
  char		*old_pwd;

  if (mysh == NULL || mysh->cmd == NULL || mysh->cmd->argv == NULL)
    return (1);
  if ((old_pwd = my_pwd()) == NULL)
    return (1);
  if (mysh->cmd->argv[1])
    {
      if (mysh->cmd->argv[1][0] == '-')
	return (my_cd_oldpwd(mysh, old_pwd));
      return (my_cd_normal(mysh, old_pwd));
    }
  return (my_cd_home(mysh, old_pwd));
}

/*
** my_check_builtins.c for my_builtins in /home/plasko_a/rendu/PSU_2013_minishell1/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Dec 16 01:12:51 2013 Antoine Plaskowski
** Last update Sun Mar  9 20:45:43 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_mysh.h"
#include	"my_tool_tab.h"
#include	"my_env.h"
#include	"my_cd.h"
#include	"my_pwd.h"
#include	"my_str.h"

static int	my_exit(t_mysh *mysh)
{
  int		status;

  if (mysh && mysh->cmd && mysh->cmd->argv)
    status = my_getnbr(mysh->cmd->argv[1]);
  else
    status = 0;
  my_free_cmd(mysh->cmd);
  my_free_tab(mysh->env);
  exit(status);
  return (1);
}

static int	my_show_pwd(t_mysh *mysh)
{
  char		*pwd;

  if (mysh == NULL)
    return (1);
  if ((pwd = my_pwd()) == NULL)
    return (1);
  my_putstr(pwd, 1);
  my_putchar('\n', 1);
  free(pwd);
  return (0);
}

static int	my_builtin_env(t_mysh *mysh)
{
  int		i;

  if (mysh == NULL || mysh->env == NULL)
    return (1);
  i = 0;
  while (mysh->env[i] != NULL)
    {
      my_putstr(mysh->env[i++], 1);
      my_putchar('\n', 1);
    }
  return (0);
}

int		my_check_builtins(t_mysh *mysh)
{
  int		(*fct[6])(t_mysh *);
  char		*builtins[6];
  int		i;

  if (mysh == NULL || mysh->cmd == NULL)
    return (1);
  builtins[0] = "cd";
  builtins[1] = "pwd";
  builtins[2] = "setenv";
  builtins[3] = "unsetenv";
  builtins[4] = "env";
  builtins[5] = "exit";
  fct[0] = &my_cd;
  fct[1] = &my_show_pwd;
  fct[2] = &my_setenv;
  fct[3] = &my_unsetenv;
  fct[4] = &my_builtin_env;
  fct[5] = &my_exit;
  i = 0;
  while (i < 6)
    if (my_strcmp(mysh->cmd->argv[0], builtins[i++]) == 0)
      return (fct[i - 1](mysh));
  return (-1);
}

/*
** my_env.c for my_env in /home/plasko_a/rendu/PSU_2013_minishell1/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Dec 16 01:43:59 2013 Antoine Plaskowski
** Last update Sun Mar  9 21:09:10 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_mysh.h"
#include	"my_tool_env.h"
#include	"my_str.h"

static int	my_add_env(t_mysh *mysh, char *str)
{
  char		**my_new_env;
  int		i;

  if (mysh == NULL || mysh->env == NULL)
    return (1);
  i = 0;
  while (mysh->env[i] != NULL)
    i++;
  if ((my_new_env = my_malloc(sizeof(char *) * (i + 2))) == NULL)
    return (1);
  i = 0;
  while (mysh->env[i] != NULL)
    {
      my_new_env[i] = mysh->env[i];
      i++;
    }
  if ((my_new_env[i++] = my_strdup(str)) == NULL)
    return (1);
  my_new_env[i] = NULL;
  free(mysh->env);
  mysh->env = my_new_env;
  return (0);
}

int		my_setenv(t_mysh *mysh)
{
  int		i;
  int		j;

  if (mysh == NULL || mysh->cmd == NULL ||
      mysh->cmd->argv == NULL || mysh->env == NULL)
    return (1);
  i = 1;
  while (mysh->cmd->argv[i] != NULL)
    {
      if ((j = my_found_env(mysh->env, mysh->cmd->argv[i])) != -1)
	{
	  if (mysh->env[j] != NULL)
	    {
	      free(mysh->env[j]);
	      if ((mysh->env[j] = my_strdup(mysh->cmd->argv[i])) == NULL)
		return (1);
	    }
	  else if (my_add_env(mysh, mysh->cmd->argv[i]))
	    return (1);
	}
      i++;
    }
  return (0);
}

static int	my_remove_env(t_mysh *mysh, int j)
{
  char		**my_new_env;
  int		i;
  int		k;

  if (mysh == NULL || mysh->env == NULL)
    return (1);
  i = 0;
  while (mysh->env[i] != NULL)
    i++;
  if ((my_new_env = my_malloc(sizeof(char *) * i)) == NULL)
    return (1);
  i = 0;
  k = 0;
  while (mysh->env[i] != NULL)
    if (i != j)
      my_new_env[k++] = mysh->env[i++];
    else
      free(mysh->env[i++]);
  my_new_env[k] = NULL;
  free(mysh->env);
  mysh->env = my_new_env;
  return (0);
}

int		my_unsetenv(t_mysh *mysh)
{
  int		i;
  int		j;

  if (mysh == NULL || mysh->cmd == NULL || mysh->cmd->argv == NULL)
    return (1);
  i = 1;
  while (mysh->cmd->argv[i] != NULL)
    {
      if ((j = my_search_env(mysh->env, mysh->cmd->argv[i])) != -1)
	{
	  if (mysh->env[j] != NULL)
	    {
	      if (my_remove_env(mysh, j))
		return (1);
	    }
	  else
	    {
	      my_putstr(mysh->cmd->argv[i], 2);
	      my_putstr(" : can't find\n", 2);
	    }
	}
      i++;
    }
  return (0);
}

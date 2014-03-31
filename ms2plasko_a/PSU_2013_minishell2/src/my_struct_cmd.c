/*
** my_struct_cmd.c for my_struct_cmd in /home/plasko_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb 19 14:23:32 2014 Antoine Plaskowski
** Last update Sun Mar  9 21:18:58 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_check_input.h"
#include	"my_create_argv.h"
#include	"my_search_redir.h"
#include	"my_struct_cmd.h"
#include	"my_tool_tab.h"
#include	"my_str.h"

static t_cmd	*my_put_cmd(t_cmd *cmd, t_cmd *new, char c)
{
  if (cmd == NULL || new == NULL)
    return (new);
  new->prev = cmd;
  if (c == '|')
    cmd->pipe = new;
  else
    cmd->coma = new;
  return (new);
}

static t_cmd	*my_init_cmd(void)
{
  t_cmd		*cmd;

  if ((cmd = my_malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  cmd->prev = NULL;
  cmd->argv = NULL;
  cmd->exe = NULL;
  cmd->dleft = NULL;
  cmd->left = NULL;
  cmd->dright = NULL;
  cmd->right = NULL;
  cmd->pipe = NULL;
  cmd->coma = NULL;
  return (cmd);
}

static t_cmd	*my_exit_cmd(t_cmd *cmd, t_cmd *new)
{
  my_putstr("error in cmd\n", 2);
  my_free_cmd(new);
  my_free_cmd(cmd);
  return (NULL);
}

t_cmd		*my_create_cmd(char **env, char *input)
{
  t_cmd		*cmd;
  t_cmd		*new;
  char		c;

  if (input == NULL)
    return (NULL);
  cmd = NULL;
  c = 0;
  while (*input != '\0')
    {
      if (!(new = my_init_cmd()) || !(new->argv = my_create_argv(input)) ||
	  !(new->exe = my_found_exe(env, new->argv[0])) ||
	  my_search_redir(new, input))
	return (my_exit_cmd(cmd, new));
      cmd = my_put_cmd(cmd, new, c);
      while (*input != ';' && *input != '|' && *input != '\0')
	input++;
      if ((c = *input) == ';' || *input == '|')
	input++;
    }
  if (cmd != NULL)
    while (cmd->prev != NULL)
      cmd = cmd->prev;
  return (cmd);
}

void		my_free_cmd(t_cmd *cmd)
{
  t_cmd		*tmp;

  if (cmd != NULL)
    {
      while (cmd->prev != NULL)
	cmd = cmd->prev;
      while (cmd != NULL)
	{
	  my_free_tab(cmd->argv);
	  free(cmd->exe);
	  free(cmd->dleft);
	  free(cmd->left);
	  free(cmd->dright);
	  free(cmd->right);
	  tmp = cmd;
	  if (cmd->pipe != NULL)
	    cmd = cmd->pipe;
	  else
	    cmd = cmd->coma;
	  free(tmp);
	}
    }
}

/*
** my_exec.c for my_exec in /home/plasko_a/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 14:48:36 2014 Antoine Plaskowski
** Last update Tue May 13 20:05:34 2014 Antoine Plaskowski
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

int		my_exec(t_btree *btree, char **envp)
{
  int		ret;

  if (btree == NULL || btree->token == NULL)
    return (0);
  if (btree->token->type == WORD)
    return (my_cmd(btree, envp));
  else if (btree->token->type == O_OR)
    {
      if ((ret = my_exec(btree->left, envp)))
	return (my_exec(btree->right, envp));
      return (0);
    }
  else if (btree->token->type == O_AND)
    {
      if (my_exec(btree->left, envp))
	return (0);
      return (my_exec(btree->right, envp));
    }
  else if (btree->token->type == O_COMMA)
    {
      my_exec(btree->left, envp);
      my_exec(btree->right, envp);
    }
  else if (btree->token->type == O_PIPE)
    {
      my_exec(btree->left, envp);
      my_exec(btree->right, envp);
    }
  return (1);
}

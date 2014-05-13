/*
** my_exec.c for my_exec in /home/plasko_a/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 14:48:36 2014 Antoine Plaskowski
** Last update Tue May 13 13:51:40 2014 Pierrick Gicquelais
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
  if (btree == NULL)
    return (1);
  while (btree->token)
    {
      my_cmd(btree, envp);
      btree->token = btree->token->next;
    }
  return (0);
}

/*
** my_exec.c for my_exec in /home/plasko_a/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 14:48:36 2014 Antoine Plaskowski
** Last update Fri May  9 15:31:41 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_btree.h"
#include	"my_str.h"

int		my_exec(t_btree *btree, char **envp)
{
  char		**tab;

  tab = malloc(2 * sizeof(char *));
  if (btree == NULL)
    return (1);
  while (btree->token)
    {
      tab[0] = my_strdup(btree->token->attribute);
      execve(my_strcat("/bin/", tab[0]), tab, envp);
      btree->token = btree->token->next;
    }
  return (0);
}

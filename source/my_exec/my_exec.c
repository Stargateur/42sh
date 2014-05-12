/*
** my_exec.c for my_exec in /home/plasko_a/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 14:48:36 2014 Antoine Plaskowski
** Last update Mon May 12 10:09:26 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_btree.h"
#include	"my_str.h"

int		my_exec(t_btree *btree, char **envp)
{
  char		**tab;
  pid_t		pid;

  tab = malloc(2 * sizeof(char *));
  if (btree == NULL)
    return (1);
  while (btree->token)
    {
      tab = my_str_to_tab(btree->token->attribute, " ");
      if ((pid = fork()) == 0)
	{
	  execve(my_strcat("/bin/", tab[0]), tab, envp);
	  my_putstr(tab[0], 1);
	  my_putstr(": command not found\n", 1);
	  exit(EXIT_SUCCESS); /* AUTORISE SEULEMENT DANS FORK */
	  return (1);
	}
      else if (pid == -1)
	return (1);
      else
	{
	  waitpid(pid, 0, WSTOPPED);
	  my_putstr("42sh> ", 1);
	}
      btree->token = btree->token->next;
    }
  return (0);
}

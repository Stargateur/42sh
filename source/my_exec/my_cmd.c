/*
** my_cmd.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 12:46:13 2014 Pierrick Gicquelais
** Last update Tue May 13 13:33:35 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_btree.h"
#include	"my_str.h"

int		my_cmd(t_btree *btree, char **envp)
{
  char		**tab;
  int		pid;

  tab = my_str_to_tab(btree->token->attribute, " ");
  if ((pid = fork()) == 0)
    {
      my_redirection(btree->token->next->next->attribute, btree->token->next->type);
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
  return (0);
}

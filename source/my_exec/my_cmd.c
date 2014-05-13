/*
** my_cmd.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 12:46:13 2014 Pierrick Gicquelais
** Last update Tue May 13 20:04:48 2014 Antoine Plaskowski
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

int		my_cmd(t_btree *btree, char **envp)
{
  char		**tab;
  int		pid;

  if ((tab = my_token_word_to_tab(btree->token)) == NULL)
    return (1);
  if ((pid = my_fork()) == 0)
    {
      /* my_redirection(btree->token->next->next->attribute, btree->token->next->type); */
      execvp(tab[0], tab);
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
    }
  my_free_tab(tab);
  return (0);
}

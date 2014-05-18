/*
** my_execve.c for my_execve in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed May 14 00:42:32 2014 Antoine Plaskowski
** Last update Sun May 18 23:00:18 2014 Antoine Plaskowski
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_shell.h"
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

int		my_execve(t_btree *btree, t_fd *fd, t_shell *shell)
{
  char		**tab;

  (void)shell;
  my_dup_fd(fd);
  if (btree == NULL)
    exit(EXIT_FAILURE); /* AUTORISE SEULEMENT DANS FORK */
  if ((tab = my_token_word_to_tab(btree->token)) == NULL)
    exit(EXIT_FAILURE); /* AUTORISE SEULEMENT DANS FORK */
  if (tab[0] == NULL)
    exit(EXIT_FAILURE); /* AUTORISE SEULEMENT DANS FORK */
  execvp(tab[0], tab);
  my_putstr(tab[0], 1);
  my_putstr(": command not found\n", 1);
  exit(EXIT_FAILURE); /* AUTORISE SEULEMENT DANS FORK */
  return (1);
}

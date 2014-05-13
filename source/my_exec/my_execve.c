/*
** my_execve.c for my_execve in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed May 14 00:42:32 2014 Antoine Plaskowski
** Last update Wed May 14 01:18:09 2014 Antoine Plaskowski
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

int		my_execve(t_btree *btree, char **env)
{
  char		**tab;

  (void)env;
  if ((tab = my_token_word_to_tab(btree->token)) == NULL)
    return (1);
  execvp(tab[0], tab);
  my_putstr(tab[0], 1);
  my_putstr(": command not found\n", 1);
  exit(EXIT_SUCCESS); /* AUTORISE SEULEMENT DANS FORK */
  return (1);
}

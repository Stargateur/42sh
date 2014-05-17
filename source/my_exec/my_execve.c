/*
** my_execve.c for my_execve in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed May 14 00:42:32 2014 Antoine Plaskowski
** Last update Sat May 17 20:02:50 2014 Antoine Plaskowski
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_exec.h"
#include	"my_btree.h"
#include	"my_str.h"

static int	my_dup_and_close(t_fd *fd)
{
  if (fd == NULL)
    return (1);
  if (fd->fd_0 != -1)
    my_dup2(fd->fd_0, 0);
  if (fd->fd_1 != -1)
    my_dup2(fd->fd_1, 1);
  if (fd->fd_pipe[0] != -1)
    my_dup2(fd->fd_pipe[0], 0);
  if (fd->fd_pipe[1] != -1)
    close(fd->fd_pipe[1]);
  return (0);
}

int		my_execve(t_btree *btree, t_fd *fd, char **env)
{
  char		**tab;

  (void)env;
  my_dup_and_close(fd);
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

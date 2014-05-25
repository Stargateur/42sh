/*
** my_redir_dleft.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_redir
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 13:41:16 2014 Pierrick Gicquelais
** Last update Sun May 25 16:34:59 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include        <signal.h>
#include	"my_exec.h"
#include	"my_str.h"

int		my_aff_redir_dleft(t_fd *fd)
{
  if (fd == NULL || fd->fd_redir[1] == -1)
    return (1);
  if ((signal(SIGPIPE, SIG_IGN)) == SIG_ERR)
    my_putstr("can't set ignore sigpipe\n", 2);
  my_aff_all_str(fd->str, fd->fd_redir[1]);
  my_free_all_str(fd->str);
  fd->str = NULL;
  if ((signal(SIGPIPE, SIG_DFL)) == SIG_ERR)
    my_putstr("can't set default sigpipe\n", 2);
  return (1);
}

int		my_redir_dleft_in_father(t_token *token, t_fd *fd)
{
  t_str		*str;
  char		*tmp;

  if ((token = my_found_token(token, O_RDLEFT)) == NULL || fd == NULL)
    return (1);
  if ((token = token->next) == NULL || token->type != WORD)
    return (1);
  str = NULL;
  while ((tmp = my_get_next_line(0)) && my_strcmp(tmp, token->attribute))
    str = my_append_str(str, tmp);
  free(tmp);
  fd->str = str;
  return (0);
}

int		my_redir_dleft(t_token *token, t_fd *fd)
{
  if (token == NULL || token->type != WORD || fd == NULL)
    return (1);
  fd->dleft = token;
  if (fd->fd_redir[0] != -1)
    close(fd->fd_redir[0]);
  if (fd->fd_redir[1] != -1)
    close(fd->fd_redir[1]);
  if (my_pipe(fd->fd_redir))
    return (1);
  return (0);
}

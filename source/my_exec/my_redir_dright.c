/*
** my_redir_dright.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 13:20:49 2014 Pierrick Gicquelais
** Last update Sat May 17 20:04:50 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_str.h"
#include	"my_exec.h"

int		my_redir_dright(t_token *token, t_fd *fd)
{
  if (token == NULL || token->type != WORD || fd == NULL)
    return (1);
  if (fd->fd_1 != -1)
    close(fd->fd_1);
  if ((fd->fd_1 = my_open_wrap(token->attribute)) == -1)
    return (1);
  return (0);
}

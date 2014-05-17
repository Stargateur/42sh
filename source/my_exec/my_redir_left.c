/*
** my_cmd_left.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_cmd
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 13:20:49 2014 Pierrick Gicquelais
** Last update Sat May 17 20:04:23 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_str.h"
#include	"my_exec.h"

int		my_redir_left(t_token *token, t_fd *fd)
{
  if (token == NULL || token->type != WORD || fd == NULL)
    return (1);
  if (fd->fd_0 != -1)
    close(fd->fd_0);
  if ((fd->fd_0 = my_open_rdonly(token->attribute)) == -1)
    return (1);
  return (0);
}

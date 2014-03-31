/*
** my_tool_redir.c for my_tool_redir in /home/plasko_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar  9 20:08:47 2014 Antoine Plaskowski
** Last update Sun Mar  9 21:14:54 2014 Antoine Plaskowski
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my_mysh.h"
#include	"my_str.h"
#include	"my_get_next_line.h"

void		my_help_redir_left_double(t_cmd *cmd, int fd_pipe[2])
{
  char		*tmp;
  t_nline	*lines;
  t_nline	*tmp_l;

  close(fd_pipe[0]);
  lines = NULL;
  while ((tmp = my_get_next_line(0)) && my_strcmp(tmp, cmd->dleft))
    my_put_new_line(&lines, tmp);
  free(tmp);
  if (lines != NULL)
    while (lines->prev != NULL)
      lines = lines->prev;
  while (lines != NULL)
    {
      my_putstr(lines->str, fd_pipe[1]);
      my_putchar('\n', fd_pipe[1]);
      tmp_l = lines;
      lines = lines->next;
      free(tmp_l->str);
      free(tmp_l);
    }
  exit(0);
}

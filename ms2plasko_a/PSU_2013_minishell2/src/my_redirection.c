/*
** my_redirection.c for my_redirection in /home/plasko_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Feb 24 14:51:50 2014 Antoine Plaskowski
** Last update Sun Mar  9 20:17:31 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_mysh.h"
#include	"my_open.h"
#include	"my_fork.h"
#include	"my_redirection.h"
#include	"my_str.h"

int		my_redir_left_simple(t_cmd *cmd)
{
  int		fd;

  if (cmd->left == NULL)
    return (0);
  if ((fd = my_open_rdonly(cmd->left)) == -1)
    return (1);
  if (dup2(fd, 0) != 0)
    {
      my_putstr("dup2 error\n", 2);
      close(fd);
      return (1);
    }
  close(fd);
  return (0);
}

int		my_redir_left_double(t_cmd *cmd)
{
  int		pid;
  int		fd_pipe[2];

  if (cmd->dleft == NULL)
    return (0);
  if (pipe(fd_pipe))
    {
      my_putstr("error pipe\n", 2);
      return (1);
    }
  if ((pid = my_fork()) == 0)
    my_help_redir_left_double(cmd, fd_pipe);
  else if (pid == -1)
    return (1);
  close(fd_pipe[1]);
  dup2(fd_pipe[0], 0);
  close(fd_pipe[0]);
  return (0);
}

int		my_redir_right_simple(t_cmd *cmd)
{
  int		fd;

  if (cmd->right == NULL)
    return (0);
  if ((fd = my_open_wrtr(cmd->right)) == -1)
    return (1);
  if (dup2(fd, 1) != 1)
    {
      my_putstr("dup2 error\n", 2);
      close(fd);
      return (1);
    }
  close(fd);
  return (0);
}

int		my_redir_right_double(t_cmd *cmd)
{
  int		fd;

  if (cmd->dright == NULL)
    return (0);
  if ((fd = my_open_wrap(cmd->dright)) == -1)
    return (1);
  if (dup2(fd, 1) != 1)
    {
      my_putstr("dup2 error\n", 2);
      close(fd);
      return (1);
    }
  close(fd);
  return (0);
}

int		my_redir(t_cmd *cmd)
{
  if (cmd == NULL)
    return (1);
  if (cmd->dright != NULL)
    {
      if (my_redir_right_double(cmd))
	return (1);
    }
  if (cmd->right != NULL)
    {
      if (my_redir_right_simple(cmd))
	return (1);
    }
  if (cmd->left != NULL)
    {
      if (my_redir_left_simple(cmd))
	return (1);
    }
  if (cmd->dleft != NULL)
    {
      if (my_redir_left_double(cmd))
	return (1);
    }
  return (0);
}

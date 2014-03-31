/*
** my_management.c for my_management in /home/plasko_a/rendu/PSU_2013_minishell1/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec 15 23:27:11 2013 Antoine Plaskowski
** Last update Sun Mar  9 22:51:12 2014 Antoine Plaskowski
*/

#define		_POSIX_SOURCE
#include	<stdlib.h>
#undef		_POSIX_SOURCE

#include	<unistd.h>
#include	<signal.h>
#include	<sys/wait.h>
#include	"my_redirection.h"
#include	"my_check_builtins.h"
#include	"my_mysh.h"
#include	"my_fork.h"
#include	"my_str.h"

static void	my_execve(t_cmd *cmd, char **env)
{
  if (cmd == NULL)
    exit(1);
  if (my_redir(cmd))
    exit(1);
  if (signal(SIGINT, SIG_DFL) == SIG_ERR)
    my_putstr("error signal\n", 2);
  if (signal(SIGTSTP, SIG_DFL) == SIG_ERR)
    my_putstr("error signal\n", 2);
  if (execve(cmd->exe, cmd->argv, env) == -1)
    {
      my_putstr("error execve\n", 2);
      exit(1);
    }
}

static int	my_launch_execve(t_cmd *cmd, char **env)
{
  int		pid;
  int		status;

  if ((pid = my_fork()) == 0)
    my_execve(cmd, env);
  else if (pid == -1)
    return (1);
  else if (waitpid(pid, &status, WUNTRACED) != pid)
    {
      my_putstr("error waitpid\n", 2);
      return (1);
    }
  if (!WIFEXITED(status))
    {
      if (kill(pid, SIGKILL))
	my_putstr("can't kill\n", 2);
    }
  return (0);
}

void		my_recur_pipe(t_cmd *cmd, char **env, int i)
{
  int		pid;
  int		fd_pipe[2];

  if (i != 0)
    {
      if (pipe(fd_pipe))
	{
	  my_putstr("error pipe\n", 2);
	  exit(1);
	}
      if ((pid = my_fork()) == 0)
	{
	  close(fd_pipe[0]);
	  dup2(fd_pipe[1], 1);
	  close(fd_pipe[1]);
	  if (cmd != NULL)
	    my_recur_pipe(cmd->prev, env, i - 1);
	}
      else if (pid == -1)
	exit(1);
      close(fd_pipe[1]);
      dup2(fd_pipe[0], 0);
      close(fd_pipe[0]);
    }
  my_execve(cmd, env);
}

static int	my_pipe(t_cmd *cmd, char **env, int i)
{
  int		pid;
  int		status;

  if ((pid = my_fork()) == 0)
    my_recur_pipe(cmd, env, i);
  else if (pid == -1)
    return (1);
  else if (waitpid(pid, &status, WUNTRACED) != pid)
    {
      my_putstr("error waitpid\n", 2);
      return (1);
    }
  if (!WIFEXITED(status))
    {
      if (kill(pid, SIGKILL))
	my_putstr("can't kill\n", 2);
    }
  return (0);
}

int		my_management(t_mysh *mysh)
{
  t_cmd		*tmp;
  int		i;

  if (mysh == NULL)
    return (1);
  tmp = mysh->cmd;
  while (mysh->cmd != NULL)
    {
      if (my_check_builtins(mysh) == -1)
	{
	  i = 0;
	  while (mysh->cmd->pipe != NULL)
	    {
	      i++;
	      mysh->cmd = mysh->cmd->pipe;
	    }
	  if (i != 0)
	    my_pipe(mysh->cmd, mysh->env, i);
	  else if (my_launch_execve(mysh->cmd, mysh->env))
	    return (1);
	}
      mysh->cmd = mysh->cmd->coma;
    }
  mysh->cmd = tmp;
  return (0);
}

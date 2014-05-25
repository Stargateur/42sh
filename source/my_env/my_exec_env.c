/*
** my_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 22 14:42:17 2014 Pierrick Gicquelais
** Last update Sun May 25 16:43:00 2014 Antoine Plaskowski
*/

#define		_POSIX_SOURCE

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	<unistd.h>
#include	"my_shell.h"
#include	"my_exec.h"
#include	"my_env.h"
#include	"my_str.h"

static int	my_micro_management(char **tab, char **env, char *exe)
{
  if (signal(SIGINT, SIG_DFL) == SIG_ERR)
    my_putstr("error signal\n", 2);
  if (signal(SIGTSTP, SIG_DFL) == SIG_ERR)
    my_putstr("error signal\n", 2);
  if (exe != NULL)
    if (execve(exe, tab, env))
      my_putstr("fail exeve\n", 2);
  free(exe);
  return (1);
}

static int	my_exec_son(char **argv, t_fd *fd, t_env *env, t_shell *shell)
{
  char		**env_tab;

  if (shell == NULL)
    return (1);
  env_tab = my_env_to_tab(env);
  my_dup_fd(fd);
  if (argv != NULL)
    {
      if (my_len_tab(argv) != 0)
	my_micro_management(argv, env_tab, my_found_exe(shell->env, argv[0]));
      my_free_tab(argv);
    }
  my_free_tab(env_tab);
  shell->exit = 1;
  shell->exit_value = 1;
  shell->exit_print = 0;
  return (1);
}

static int	my_son(t_env *env, char **argv, t_fd *fd, t_shell *shell)
{
  if (fd->fd_redir[1] != -1)
    {
      my_free_all_str(fd->str);
      close(fd->fd_redir[1]);
      fd->fd_redir[1] = -1;
    }
  return (my_exec_son(argv, fd, env, shell));
}

static int	my_father(t_fd *fd, int pid)
{
  int		ret;

  if (fd->fd_redir[1] != -1)
    my_aff_redir_dleft(fd);
  my_close_fd(fd);
  if (waitpid(pid, &ret, WUNTRACED) != pid)
    my_putstr("waitpid error\n", 2);
  if (WIFEXITED(ret))
    return (WEXITSTATUS(ret));
  if (WIFSIGNALED(ret))
    my_aff_signal(WTERMSIG(ret));
  if (WIFSTOPPED(ret))
    {
      my_putstr("no job control we kill your prog\n", 2);
      kill(pid, SIGKILL);
    }
  return (1);
}

int		my_env_exec(t_env *env, char **argv, t_fd *fd, t_shell *shell)
{
  int		pid;

  if ((pid = fork()) == 0)
    return (my_son(env, argv, fd, shell));
  else if (pid == -1)
    return (my_put_error("can't fork... \n"));
  my_free_tab(argv);
  return (my_father(fd, pid));
}

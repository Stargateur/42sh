/*
** minishell2.c for minishell2 in /home/costa_b/rendu/PSU_2013_minishell2
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Feb 20 17:36:48 2014 Kevin Costa
** Last update Fri Mar  7 18:21:42 2014 Kevin Costa
*/

#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<dirent.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"my.h"

int		minishell2(char **env)
{
  char		**wordtab;
  char		*buffer;
  pid_t		pid;
  int		status;
  char		**path;

  if (env == NULL)
    return (1);
  while (42)
    {
      my_putstr("$>");
      buffer = get_next_line(0);
      wordtab = my_str_to_wordtab(buffer);
      path = my_path(env);
      check_buffer(buffer);
      pid = fork();
      if (pid == 0)
	my_exec(wordtab, env, path);
      else if (pid == -1)
	my_put_error("Error\n");
      else
	wait(&status);
      free(buffer);
    }
}

int		my_cmd(char **wordtab, char **env, char **path)
{
  DIR		*derp;
  struct	dirent *entry;
  int		a;

  a = 0;
  while (path[a] != '\0')
    {
      if ((derp = opendir(path[a])) == NULL)
	{
	  my_putstr("Error command not found\n");
	  exit(-1);
	}
      while ((entry = readdir(derp)) != NULL)
	my_execlp(entry->d_name, path[a], wordtab, env);
      closedir(derp);
      a++;
    }
  return (0);
}

void		check_exit(char *buffer)
{
  if (my_strcmp(buffer, "exit") == 0)
    exit(0);
}

int		main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  signal(SIGINT, SIG_IGN);
  minishell2(cpy_env(env));
  return (0);
}

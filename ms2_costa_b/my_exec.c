/*
** my_exec.c for my_exec in /home/costa_b/rendu/PSU_2013_minishell2
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Fri Mar  7 18:20:09 2014 Kevin Costa
** Last update Fri Mar  7 18:22:30 2014 Kevin Costa
*/

#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<dirent.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"my.h"

int		my_exec(char **wordtab, char **env, char **path)
{
  execve(wordtab[0], wordtab, env);
  my_cmd(wordtab, env, path);
  my_putstr("Error command not found\n");
  return (-1);
}

char		*my_add_str(char *s, char *d)
{
  char		*p;
  int		i;

  i = 0;
  if ((p = malloc(sizeof(char *) * (my_strlen(s) + my_strlen(d) + 2))) == NULL)
    exit(1);
  while (*s)
    {
      p[i] = *s++;
      i++;
    }
  p[i++] = '/';
  while (*d)
    {
      p[i] = *d++;
      i++;
    }
  p[i] = '\0';
  return (p);
}

void		my_execlp(char *name, char *path, char **wordtab, char **env)
{
  char		**add;

  if ((add = malloc(sizeof(char *) * 2)) == NULL)
    exit(1);
  if ((my_strcmp(name, wordtab[0])) == 0)
    {
      add[0] = my_add_str(path, name);
      execve(add[0], wordtab, env);
    }
}

/*
** my_prompt.c for 42sh in /home/makusa_n/depot_git/PSU_2013_42sh/my_prompt
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Fri May 16 12:05:23 2014 Nayden Makusa
** Last update Mon May 19 09:56:42 2014 Nayden Makusa
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"get_next_line.h"

int		my_check_open_file(char *av)
{
  int		fd;

  if ((fd = open(av, O_RDONLY)) == -1)
    {
      my_putstr("Error: can't open the prompt file.\n");
      return (1);
    }
  return (0);
}

int		my_check_empty_string(char *av)
{
  int		fd;
  char		*str;

  while ((str = get_next_line(fd)) != NULL)
    {
      if (str[0] == '\0')
	{
	  my_putstr("Error: a string is empty.\n");
	  return (1);
	}
    }
  close(fd);
  return (0);
}

char		*my_prompt(int count_prompt, char *str)
{
  if (str == NULL)
    return (NULL);
  my_putstr(str);
  return (str);
}

int		my_conf(char *av)
{
  int		fd;
  int		count_prompt;
  char		*str;

  fd = open(av, O_RDONLY);
  count_prompt = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (count_prompt == 1)
	{
	  my_prompt(count_prompt, str);
	  count_prompt = 2;
	}
      if (my_strcmp_maj(str, "prompt") == 0)
	count_prompt = 1;
    }
  if (count_prompt == 1 || count_prompt == 0)
    {
      my_putstr("Error: problem with the prompt.\n");
      exit(1);
    }
  close(fd);
  my_putchar('\n');
  return (0);
}

int		main(int ac, char **av)
{
  (void)ac;
  if (my_check_open_file(av[1]) == 1)
    return (1);
  if (my_check_empty_string(av[1]) == 1)
    return (1);
  my_conf(av[1]);
}

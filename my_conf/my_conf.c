/*
** my_prompt.c for 42sh in /home/makusa_n/depot_git/PSU_2013_42sh/my_prompt
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Fri May 16 12:05:23 2014 Nayden Makusa
** Last update Mon May 19 15:03:09 2014 Nayden Makusa
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"get_next_line.h"

char		*g_my_prompt;

int		my_conf(char *av)
{
  int		fd;
  int		count_prompt;
  int		count_alias;
  char		*str;

  fd = open(av, O_RDONLY);
  count_prompt = 0;
  count_alias = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (my_strcmp_maj(str, "alias") == 0 && count_alias == 0 && count_prompt != 1)
	count_alias = 1;
      if (count_prompt == 1)
	{
	  g_my_prompt = str;
	  count_prompt = 2;
	}
      if (my_strcmp_maj(str, "prompt") == 0 && count_prompt == 0)
	count_prompt = 1;
    }
  my_check_prompt_string(count_prompt, count_alias);
  close(fd);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac != 2)
    {
      my_putstr("Error: problem with the parameters.\n");
      return (1);
    }
  if (my_check_open_file(av[1]) == 1)
    return (1);
  if (my_check_empty_string(av[1]) == 1)
    return (1);
  my_conf(av[1]);
  my_putstr(g_my_prompt);
  my_putchar('\n');
}

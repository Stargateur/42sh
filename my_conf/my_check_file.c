/*
** my_check_file.c for 42sh in /home/makusa_n/depot_git/PSU_2013_42sh/my_conf
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Mon May 19 10:27:57 2014 Nayden Makusa
** Last update Wed May 21 17:50:12 2014 Nayden Makusa
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
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

int		my_check_file_message(int count_prompt, int count_alias)
{
  if (count_prompt == 0 || count_prompt == 1)
    {
      my_putstr("Error: problem with the prompt.\n");
      return (1);
    }
  if (count_alias == 1)
    {
      my_putstr("Error: there isn't the 'end' after the 'alias'.\n");
      return (1);
    }
  if (count_alias == 0)
    {
      my_putstr("Error: problem with an alias.\n");
      return (1);
    }
  return (0);
}

int		my_check_file(char *av)
{
  int		fd;
  char		*str;
  int		count_prompt;
  int		count_alias;

  fd = open(av, O_RDONLY);
  count_prompt = 0;
  count_alias = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (str[0] == '\0')
	{
	  my_putstr("Error: a string is empty.\n");
	  return (1);
	}
      if (my_strcmp_maj(str, "end") == 0 && count_alias == 1 && count_prompt != 1)
	count_alias = 2;
      if (count_prompt == 1)
	count_prompt = 2;
      if (my_strcmp_maj(str, "alias") == 0 && count_alias == 0 && count_prompt != 1)
	count_alias = 1;
      if (my_strcmp_maj(str, "prompt") == 0 && count_prompt == 0 && count_alias != 1)
	count_prompt = 1;
    }
  if (my_check_file_message(count_prompt, count_alias) == 1)
    return (1);
  close(fd);
  return (0);
}

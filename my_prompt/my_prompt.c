/*
** my_prompt.c for 42sh in /home/makusa_n/depot_git/PSU_2013_42sh/my_prompt
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Fri May 16 12:05:23 2014 Nayden Makusa
** Last update Fri May 16 13:59:47 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"get_next_line.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_prompt(char *av)
{
  int		fd;
  char		*str;

  if ((fd = open(av, O_RDONLY)) == -1)
    {
      printf("Error: can't open the prompt file.\n");
      return (1);
    }
  if ((str = get_next_line(fd)) == NULL)
    {
      printf("Error: the file is empty or the last character ");
      printf("of the file is not a new line.\n");
      return (1);
    }
  if (str[0] == '\0')
    {
      printf("Error: the prompt's string is empty.\n");
      return (1);
    }
  int		a = -1;
  while (str[++a] != '\0')
    my_putchar(str[a]);
  my_putchar('\n');
  return (0);
}

int		main(int ac, char **av)
{
  (void)ac;
  my_prompt(av[1]);
}

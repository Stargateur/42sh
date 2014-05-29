/*
** my_prompt.c for 42sh in /home/makusa_n/depot_git/PSU_2013_42sh/my_prompt
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Fri May 16 12:05:23 2014 Nayden Makusa
** Last update Thu May 29 21:16:26 2014 Nayden Makusa
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"conf.h"

list		put_end_list(list liste, char *value)
{
  element	*new;
  element	*tmp;

  tmp = liste;
  new = malloc(sizeof(element));
  new->val = value;
  new->next = NULL;
  if (liste == NULL)
    return (new);
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      return (liste);
    }
}

void		aff_list(list chain)
{
  element	*tmp;

  tmp = chain;
  while (tmp != NULL)
    {
      my_putstr(tmp->val);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

list		my_conf(char *av, list chain)
{
  int		fd;
  char		*str;
  int		count_alias;

  fd = open(av, O_RDONLY);
  count_alias = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (my_strcmp_maj(str, "end") == 0)
	count_alias = 2;
      if (count_alias == 1)
	chain = put_end_list(chain, str);
      if (my_strcmp_maj(str, "alias") == 0)
	count_alias = 1;
    }
  close(fd);
  return (chain);
}

int		main(int ac, char **av)
{
  list		chain;

  chain = NULL;
  if (ac != 2)
    {
      my_putstr("Error: problem with the parameters.\n");
      return (1);
    }
  if (my_check_open_file(av[1]) == 1)
    return (1);
  if (my_check_flag(av[1]) == 1)
    return (1);
  if (my_check_order_flag(av[1]) == 1)
    return (1);
  if (my_check_equal_liste(av[1]) == 1)
    return (1);
  chain = my_conf(av[1], chain);
  aff_list(chain);
}

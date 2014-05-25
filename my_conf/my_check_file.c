/*
** my_check_file.c for 42sh in /home/makusa_n/depot_git/PSU_2013_42sh/my_conf
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Mon May 19 10:27:57 2014 Nayden Makusa
** Last update Sun May 25 15:51:54 2014 Antoine Plaskowski
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

int		my_check_order_flag_message(int verif_alias_end,
					    int verif_equal, int no_alias)
{
  if (verif_alias_end != 2)
    {
      my_putstr("Error: the prompt must be appart from the alias.\n");
      return (1);
    }
  if (verif_equal == 1)
    {
      my_putstr("Error: there isn't an equal in an ");
      my_putstr("alias' line in the conf file.\n");
      return (1);
    }
  if (no_alias == 0)
    return (2);
}

int		my_check_flag_message(int verif_prompt, int verif_alias,
				      int verif_end, int verif_empty)
{
  if (verif_empty == 1)
    {
      my_putstr("Error: there is an empty string in the conf file.\n");
      return (1);
    }
  if (verif_prompt == 1)
    {
      my_putstr("Error: there isn't the string 'prompt' in the conf file.\n");
      return (1);
    }
  if (verif_end == 1)
    {
      my_putstr("Error: there isn't the string 'end' in the conf file.\n");
      return (1);
    }
  if (verif_alias == 1)
    {
      my_putstr("Error: there isn't the string 'alias' in the conf file.\n");
      return (1);
    }
  return (0);
}

int		my_check_order_flag(char *av)
{
  int		fd;
  char		*str;
  int		verif_alias_end;
  int		verif_equal;
  int		no_alias;

  fd = open(av, O_RDONLY);
  verif_alias_end = 0;
  no_alias = 0;
  verif_equal = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (my_strcmp_maj(str, "end") == 0 && verif_alias_end == 1)
	verif_alias_end = 2;
      if (my_check_equal(str) == 1 && verif_alias_end == 1)
	verif_equal = 1;
      if (my_check_equal(str) == 0 && verif_alias_end == 1)
	no_alias = 1;
      if (my_strcmp_maj(str, "alias") == 0)
	verif_alias_end = 1;
    }
  close(fd);
  if (my_check_order_flag_message(verif_alias_end, verif_equal, no_alias) == 1)
    return (1);
  return (0);
}

int		my_check_flag(char *av)
{
  int		fd;
  char		*str;
  int		verif[3];
  int		verif_empty;

  fd = open(av, O_RDONLY);
  verif[0] = 1;
  verif[1] = 1;
  verif[2] = 1;
  verif_empty = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (str[0] == '\0')
	verif_empty = 1;
      if (my_strcmp_maj(str, "end") == 0)
	verif[0] = 0;
      if (my_strcmp_maj(str, "alias") == 0)
	verif[1] = 0;
      if (my_strcmp_maj(str, "prompt") == 0)
	verif[2] = 0;
    }
  close(fd);
  if (my_check_flag_message(verif[2], verif[1], verif[0], verif_empty) == 1)
    return (1);
  return (0);
}

/*
** my_check_file.c for 42sh in /home/makusa_n/depot_git/PSU_2013_42sh/my_conf
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Mon May 19 10:27:57 2014 Nayden Makusa
** Last update Thu May 29 17:21:34 2014 Nayden Makusa
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
      my_putstr("Error: can't open the conf file.\n");
      return (1);
    }
  return (0);
}

static void	my_check_multiple_flag(int *mul_alias, int *mul_end,
				       int *mul_prompt, char *str)
{
  if (my_strcmp_maj(str, "alias") == 0)
    (*mul_alias)++;
  if (my_strcmp_maj(str, "end") == 0)
    (*mul_end)++;
  if (my_strcmp_maj(str, "prompt") == 0)
    (*mul_prompt)++;
}

int		my_check_order_flag(char *av)
{
  int		fd;
  char		*str;
  int		verif;
  int		mul[3];

  verif = 0;
  mul[0] = 0;
  mul[1] = 0;
  mul[2] = 0;
  fd = open(av, O_RDONLY);
  while ((str = get_next_line(fd)) != NULL)
    {
      my_check_multiple_flag(&mul[0], &mul[1], &mul[2], str);
      if (my_strcmp_maj(str, "alias") == 0)
	verif = 1;
      if (my_strcmp_maj(str, "end") == 0 && verif == 1)
	verif = 2;
      if (my_strcmp_maj(str, "prompt") == 0 && verif == 2)
	verif = 3;
    }
  close(fd);
  if (my_check_order_flag_message(verif, mul[0], mul[1], mul[2]) == 1)
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

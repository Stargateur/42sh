/*
** my_cd.c for my_cd in /home/plasko_a/programation/epitech/PSU_2013_42sh/source
**
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
**
** Started on  Mon May 19 02:32:40 2014 Antoine Plaskowski
** Last update Fri May 23 10:41:45 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<dirent.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"my_shell.h"
#include	"my_str.h"

int		my_cd(t_shell *shell, t_fd *fd, char **argv)
{
  char		*old;
  char		*new;

  if (!(old = malloc(sizeof(char) * 2048)))
    return (1);
  if (!(new = malloc(sizeof(char) * 2048)))
    return (1);
  old = getcwd(old, 2048);
  if (argv[1] == NULL)
    argv[1] = "/home"; /* remplacer le dossier par le home */
  else if ((my_strcmp(argv[1], "-")) == -1)
    {
      my_putstr("Wrong option for cd\n");
      return (-1);
    }
  if (argv[1] == '-')
    argv[1] = old;
  if (chdir(argv[1]) == -1)
    {
      my_putstr("Wrong direction\n");
      return (-1);
    }
  new = getcwd(new, 2048);
  /* printf("\033[31mje suis le old :%s\n", old); */
  /* printf("\033[34mje suis le new :%s\n\033[0m", new); */
  return (0);
}

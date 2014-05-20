/*
** my_cd.c for my_cd in /home/plasko_a/programation/epitech/PSU_2013_42sh/source
**
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
**
** Started on  Mon May 19 02:32:40 2014 Antoine Plaskowski
** Last update Mon May 19 03:04:23 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<dirent.h>
#include	<unistd.h>
#include	<stdio.h>
/* #include	"my_shell.h" */
/* #include	"my_str.h" */

/* int		my_cd(t_shell *shell, t_fd *fd, char **argv) */
/* { */
/*   return (0); */
/* } */

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  while (*str)
    my_putchar(*str++);
}

int		main(int ac, char **argv)
{
  if (argv[1] == NULL)
    argv[1] = "/home/costa_b"; /* a la base ici c'est la variable Home de l'env */
  if (chdir(argv[1]) == -1)
    {
      my_putstr("Wrong direction\n");
      return (-1);
    }
  system("pwd");
  return (0);
}

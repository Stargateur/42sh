/*
** my_fputchar.c for fputchar in /home/marsil_g/rendu/crypt/functions
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Wed May 14 09:32:38 2014 Gabriele Marsili
** Last update Wed May 14 11:13:37 2014 Gabriele Marsili
*/

#include	<unistd.h>

void		my_fputchar(const int fd, char c)
{
  write(fd, &c, 1);
}

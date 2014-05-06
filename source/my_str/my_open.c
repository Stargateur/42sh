/*
** my_bmp.c for my_bmp in /home/plasko_a/rendu/MUL_2013_wof3d/src/
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct 24 16:05:36 2013 Antoine Plaskowski
** Last update Tue May  6 13:25:35 2014 Antoine Plaskowski
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	"my_str.h"

#define		FLAGS_RIGHT	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

int		my_open_rdonly(const char *str)
{
  int		fd;

  if ((fd = open(str, O_RDONLY)) == -1)
    {
      my_putstr(str, 2);
      my_putstr(" : can't open\n", 2);
    }
  return (fd);
}

int		my_open_wrap(const char *str)
{
  int		fd;

  if ((fd = open(str, O_CREAT | O_WRONLY | O_APPEND, FLAGS_RIGHT)) == -1)
    {
      my_putstr(str, 2);
      my_putstr(" : can't open\n", 2);
    }
  return (fd);
}

int		my_open_wrtr(const char *str)
{
  int		fd;

  if ((fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, FLAGS_RIGHT)) == -1)
    {
      my_putstr(str, 2);
      my_putstr(" : can't open\n", 2);
    }
  return (fd);
}

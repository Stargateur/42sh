/*
** check_buffer.c for check_buffer in /home/costa_b/rendu/PSU_2013_minishell2
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Fri Mar  7 18:13:56 2014 Kevin Costa
** Last update Fri Mar  7 18:23:10 2014 Kevin Costa
*/

#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<dirent.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"my.h"

int		check_buffer(char *buffer)
{
  if (buffer == '\0')
    {
      my_putchar('\n');
      exit(0);
    }
  check_exit(buffer);
  return (0);
}

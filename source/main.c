/*
** main.c for main in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 14:47:16 2014 Antoine Plaskowski
** Last update Mon May  5 15:42:11 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_str.h"

int		main(int argc, char **argv)
{
  char		*str;

  argv[argc] = NULL;
  while ((str = my_get_next_line(0)) != NULL)
    {
      my_token(str);
      free(str);
    }
  return (0);
}

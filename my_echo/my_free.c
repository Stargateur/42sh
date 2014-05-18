/*
** my_free.c for free in /home/marsil_g/Documents/PSU/42sh
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Sun May 18 14:53:52 2014 Gabriele Marsili
** Last update Sun May 18 14:55:49 2014 Gabriele Marsili
*/

#include	<stdlib.h>
#include	"includes.h"

void            my_free(char **tab)
{
  int           i;
  i = -1;

  while(tab[++i] != NULL)
    free(tab[i]);
  free(tab);
}

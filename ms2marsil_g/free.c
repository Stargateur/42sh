/*
** free.c for free in /home/marsil_g/Documents/PSU/PSU-MS1/MS
** 
** Made by marsil_g
** Login   <marsil_g@epitech.net>
** 
** Started on  Wed Mar  5 15:52:35 2014 marsil_g
** Last update Fri Mar  7 13:17:42 2014 marsil_g
*/

#include	<stdlib.h>
#include	"my.h"

void		free1(char **pth, char **env)
{
  free_pth(pth);
  free_env(env);
}

void		free_tab(char **tab)
{
  int		i;

  i = -1;
  if (tab[0] != 0)
    {
      while (tab[++i])
	free(tab[i]);
      free(tab);
    }
}

void		free_pth(char **pth)
{
  int		i;

  i = -1;
  if (pth[0] != 0)
    {
      while (pth[++i])
	free(pth[i]);
      free(pth);
    }
}

void		free_env(char **my_env)
{
  int		i;

  i = -1;
  if (my_env[0] != 0)
    {
      while (my_env[++i])
	free(my_env[i]);
      free(my_env);
    }
}

void		free_all(char **tab, char **pth, char **my_env)
{
  free_tab(tab);
  free_pth(pth);
  free_env(my_env);
}

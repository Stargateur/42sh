/*
** my_exec_or.c for my_exec_or in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue May 13 21:51:25 2014 Antoine Plaskowski
** Last update Tue May 13 21:59:20 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_exec.h"

int		my_exec_or(t_btree *btree, char **env)
{
  int		ret;

  my_exec(btree->left, env);
  my_exec(btree->right, env);
  return (0);
}

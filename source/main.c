/*
** main.c for main in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 14:47:16 2014 Antoine Plaskowski
** Last update Fri May  9 15:25:20 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_token.h"
#include	"my_btree.h"
#include	"my_str.h"
#include	"my_exec.h"

int		main(int argc, char **argv, char **envp)
{
  t_token	*token;
  t_btree	*btree;
  char		*str;

  (void)argc;
  (void)argv;
  while ((str = my_get_next_line(0)) != NULL)
    {
      token = my_token(str);
      btree = my_btree(token);
      my_aff_all_btree(btree, 1);
      my_exec(btree, envp);
      free(str);
    }
  return (0);
}

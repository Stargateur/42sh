/*
** my_exec_dleft.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 13 13:41:16 2014 Pierrick Gicquelais
** Last update Fri May 16 14:40:19 2014 Pierrick Gicquelais
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my_str.h"
#include	"my_exec.h"

int		my_exec_dleft(t_btree *btree, char **env)
{
  t_list	*list;
  char		*s;
  int		save_fd;

  list = NULL;
  save_fd = dup(1);
  while ((s = my_get_next_line(0)) && my_strcmp(s, btree->right->token->attribute))
    {
      if ((list = my_append_list(list, s)) == NULL)
	return (1);
      free(s);
    }
  dup2(0, 1);
  my_aff_all_list(list);
  my_free_all_list(list);
  if (my_exec(btree->left, env))
    {
      dup2(save_fd, 1);
      return (1);
    }
  dup2(save_fd, 1);
  return (0);
}

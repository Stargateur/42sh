/*
** my_aff_history.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 28 18:37:22 2014 Pierrick Gicquelais
** Last update Wed May 28 22:28:02 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_history.h"
#include	"my_shell.h"
#include	"my_str.h"

void		my_aff_history(t_histo *history)
{
  if (history != NULL)
    {
      my_putchar(' ', 1);
      my_putnbr(history->id, 1);
      my_putchar('\t', 1);
      my_putstr(history->att, 1);
      my_putchar('\n', 1);
    }
}

int		my_aff_all_history(t_shell *shell, t_fd *fd, char **argv)
{
  (void)fd;
  (void)argv;
  shell->history = my_first_history(shell->history);
  while (shell->history != NULL)
    {
      my_aff_history(shell->history);
      shell->history = shell->history->next;
    }
  return (0);
}

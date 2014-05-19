/*
** my_history.h for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 19 13:40:16 2014 Pierrick Gicquelais
** Last update Mon May 19 14:58:17 2014 Pierrick Gicquelais
*/

#ifndef		MY_HISTORY_H_
# define	MY_HISTORY_H_

typedef	struct	s_histo	t_histo;

struct		s_histo
{
  t_histo	*prev;
  t_histo	*next;
  int		id;
  char		*att;
};

t_histo		*my_new_history();
t_histo		*my_first_history(t_histo *);
t_histo		*my_last_history(t_histo *);
t_histo		*my_append_history(t_histo *, int *, char *);
void		my_aff_all_history(t_histo *);
void		my_free_all_history(t_histo *);

#endif		/* !MY_HISTORY_H_ */

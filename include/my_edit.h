/*
** my_edit.h for my_edit in /home/plasko_a/programation/epitech/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu May 29 14:39:26 2014 Antoine Plaskowski
** Last update Thu May 29 19:02:11 2014 Pierrick Gicquelais
*/

#ifndef		MY_EDIT_H_
# define	MY_EDIT_H_

# include	"my_env.h"

typedef struct	s_edit	t_edit;

struct		s_edit
{
  t_edit	*prev;
  t_edit	*next;
  char		c;
};

t_edit		*my_new_char();
t_edit		*my_first_char(t_edit *edit);
t_edit		*my_last_char(t_edit *edit);
t_edit		*my_append_char(t_edit *edit, char c);
t_edit		*my_sup_char(t_edit *edit);
void		my_aff_char(t_edit *edit);
void		my_aff_all_char(t_edit *edit);
void		my_free_char(t_edit *edit);
void		my_free_all_char(t_edit *edit);

int		term_init(t_env *env);

#endif		/* !MY_EDIT_H_ */

/*
** my_editor.h for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_editor
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 20 17:00:16 2014 Pierrick Gicquelais
** Last update Wed May 21 15:52:31 2014 Pierrick Gicquelais
*/

#ifndef		MY_EDITOR_H_
# define	MY_EDITOR_H_

# include	<termios.h>
# define	FALSE	(0)
# define	TRUE	(1)

typedef	struct	s_edit	t_edit;
typedef		int	bool;

struct		s_edit
{
  t_edit	*prev;
  t_edit	*next;
  char		c;
  bool		flag;
};

t_edit		*my_new_editor();
t_edit		*my_first_char(t_edit *);
t_edit		*my_last_char(t_edit *);
t_edit		*my_append_char(t_edit *, char);
int		my_putchar(char);
int		raw_attr(struct termios *);
int		canon_attr(struct termios *);
int		is_printable(char);
int		is_enter(char);
int		is_delete(char);
int		is_left(char *);
int		is_right(char *);
void		my_aff_editor(t_edit *);
void		my_free_editor(t_edit *);

#endif		/* !MY_EDITOR_H_ */

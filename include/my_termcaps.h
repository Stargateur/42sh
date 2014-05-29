/*
** my_termcaps.h for my_termcaps in /home/plasko_a/programation/epitech/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu May 29 14:09:43 2014 Antoine Plaskowski
** Last update Thu May 29 19:00:09 2014 Antoine Plaskowski
*/

#ifndef		MY_TERMCAPS_H_
# define	MY_TERMCAPS_H_

# include	<term.h>

# undef		tab

typedef	struct	termios	t_ter;

int		my_echo_off(t_ter *t);
int		my_raw_mode(t_ter *t);
int		my_reset(t_ter *t);
int		my_tcgetattr(t_ter *t);
int		my_tcsetattr(t_ter *t);
int		my_tgetent(char *str);
char		*my_tgetstr(char *str);
int		my_putint(int i);

#endif		/* !MY_TERMCAPS_H_ */

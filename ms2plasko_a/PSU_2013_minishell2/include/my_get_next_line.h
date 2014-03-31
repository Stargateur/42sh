/*
** my_get_next_line.h for my_get_next_line in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Feb 12 15:22:45 2014 Antoine Plaskowski
** Last update Sun Mar  9 16:59:43 2014 Antoine Plaskowski
*/

#ifndef		MY_GET_NEXT_LINE_H_
# define	MY_GET_NEXT_LINE_H_

# define	BUF			4096

typedef struct	s_nline t_nline;
struct		s_nline
{
  t_nline	*prev;
  char		*str;
  t_nline	*next;
};

int		my_put_new_line(t_nline **new_line, char *str);
char		*my_get_next_line(const int fd);

#endif		/* MY_GET_NEXT_LINE_H_ */

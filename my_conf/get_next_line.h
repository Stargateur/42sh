/*
** get_next_line.h for get_next_line in /home/makusa_n/rendu/Allum1
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Tue Feb  4 11:25:34 2014 Nayden Makusa
** Last update Sun May 25 15:50:57 2014 Antoine Plaskowski
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

# define	BUFF_SIZE	1

typedef	struct	s_list	t_list;

struct		s_list
{
  char		c;
  t_list	*next;
};

char		*get_next_line(const int);

#endif		/* !GET_NEXT_LINE_H_ */

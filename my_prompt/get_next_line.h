/*
** get_next_line.h for get_next_line in /home/makusa_n/rendu/Allum1
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Tue Feb  4 11:25:34 2014 Nayden Makusa
** Last update Tue Feb 11 19:58:04 2014 Nayden Makusa
*/

# define	BUFF_SIZE	10

typedef	struct	s_list	t_list;

struct		s_list
{
  char		c;
  t_list	*next;
};

char		*get_next_line(const int);

/*
** my_token.h for my_token in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 15:14:12 2014 Antoine Plaskowski
** Last update Mon May  5 15:21:55 2014 Antoine Plaskowski
*/

#ifndef		MY_TOKEN_H_
# define	MY_TOKEN_H_

typedef	struct	s_token	t_token;

struct		s_token
{
  int		token;
  char		*pattern;
  t_token	*next;
};

t_token		*my_token(char *str);

#endif		/* !MY_TOKEN_H_ */

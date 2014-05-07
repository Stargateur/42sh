/*
** my_token.h for my_token in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 15:14:12 2014 Antoine Plaskowski
** Last update Tue May  6 19:45:08 2014 Pierrick Gicquelais
*/

#ifndef		MY_TOKEN_H_
# define	MY_TOKEN_H_

typedef	struct	s_token	t_token;

struct		s_token
{
  enum
    {
      WORD,
      PIPE,
      O_OR,
      O_AND,
      COMA,
      R_L,
      R_DL,
      R_R,
      R_DR,
      NONE
    }		token;
  int		tok;
  char		*pattern;
  t_token	*next;
};

t_token		*my_token(char *str);

#endif		/* !MY_TOKEN_H_ */

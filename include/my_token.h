/*
** my_token.h for my_token in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 15:14:12 2014 Antoine Plaskowski
** Last update Wed May  7 17:38:49 2014 Antoine Plaskowski
*/

#ifndef		MY_TOKEN_H_
# define	MY_TOKEN_H_

typedef	struct	s_token	t_token;

struct		s_token
{
  t_token	*prev;
  t_token	*next;
  char		*attribute;
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
    }		type;
};

t_token		*my_token(char *str);

t_token		*my_first_token(t_token *token);

t_token		*my_last_token(t_token *token);

t_token		*my_append_token(t_token *old, char *attribute, int type);

/*
**		my_free_token.c
*/

void		my_free_token(t_token *token);

void		my_free_all_token(t_token *token);

/*
*/

/*
**		my_aff_token.c
*/

int		my_aff_token(t_token *token, const int fd);

int		my_aff_all_token(t_token *token, const int fd);

/*
*/

#endif		/* !MY_TOKEN_H_ */

/*
** my_token.h for my_token in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 15:14:12 2014 Antoine Plaskowski
** Last update Fri May  9 10:46:47 2014 Antoine Plaskowski
*/

#ifndef		MY_TOKEN_H_
# define	MY_TOKEN_H_

# define	TOKEN		"|&;<>"

# define	SEPARATOR	" \t\n"

#include	"my_typedef.h"

typedef	struct	s_token	t_token;

struct		s_token
{
  t_token	*prev;
  t_token	*next;
  char		*attribute;
  enum
    {
      WORD,
      O_OR,
      O_AND,
      O_COMA,
      O_PIPE,
      O_RLEFT,
      O_RDLEFT,
      O_RRIGHT,
      O_RDRIGHT,
      NONE = 0
    }		type;
};

t_token		*my_token(char *str);

t_token		*my_first_token(t_token *token);

t_token		*my_last_token(t_token *token);

t_token		*my_append_token(t_token *old, char *attribute, int type);

t_token		*my_put_token(t_token *old, t_token *token);

t_uint		my_len_token(t_token *token);

t_token		*my_new_token(void);

t_token		*my_word_token(char *str, int *i);

t_token		*my_pipe_token(char *str, int *i);

t_token		*my_esperluette_token(char *str, int *i);

t_token		*my_coma_token(char *str, int *i);

t_token		*my_redirection_left_token(char *str, int *i);

t_token		*my_redirection_right_token(char *str, int *i);

t_token		*my_redirection_double_left_token(char *str, int *i);

t_token		*my_redirection_double_right_token(char *str, int *i);

t_token		*my_or_token(char *str, int *i);

t_token		*my_and_token(char *str, int *i);

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

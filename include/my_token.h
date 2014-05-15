/*
** my_token.h for my_token in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 15:14:12 2014 Antoine Plaskowski
** Last update Thu May 15 22:55:38 2014 Antoine Plaskowski
*/

#ifndef		MY_TOKEN_H_
# define	MY_TOKEN_H_

# define	TOKEN		"|&;<>"

# define	SEPARATOR	" \t\n"

#include	"my_typedef.h"

typedef	struct	s_token	t_token;

typedef	enum	s_type
  {
    WORD = 1,
    O_OR = 2,
    O_AND = 3,
    O_COMMA = 4,
    O_PIPE = 5,
    O_RLEFT = 6,
    O_RDLEFT = 7,
    O_RRIGHT = 8,
    O_RDRIGHT = 9,
    NONE = 0
  }		t_type;

typedef	enum	s_priority
  {
    P_WORD = 0,
    P_O_OR = 2,
    P_O_AND = 2,
    P_O_COMMA = 1,
    P_O_PIPE = 3,
    P_O_RLEFT = 4,
    P_O_RDLEFT = 4,
    P_O_RRIGHT = 4,
    P_O_RDRIGHT = 4,
    P_NONE = 0
  }		t_priority;

struct		s_token
{
  t_token	*prev;
  t_token	*next;
  t_type	type;
  t_priority	priority;
  char		*attribute;
};

t_token		*my_token(char *str);

char		**my_token_word_to_tab(t_token *token);

t_token		*my_first_token(t_token *token);

t_token		*my_last_token(t_token *token);

t_token		*my_append_token(t_token *old, char *attribute, int type);

t_token		*my_put_token(t_token *old, t_token *token);

t_uint		my_len_token(t_token *token);

t_token		*my_new_token(void);

t_token		*my_word_token(char *str, int *i);

t_token		*my_pipe_token(char *str, int *i);

t_token		*my_esperluette_token(char *str, int *i);

t_token		*my_comma_token(char *str, int *i);

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

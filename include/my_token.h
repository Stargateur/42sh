/*
** my_token.h for my_token in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon May  5 15:14:12 2014 Antoine Plaskowski
** Last update Mon May 19 03:32:47 2014 Antoine Plaskowski
*/

#ifndef		MY_TOKEN_H_
# define	MY_TOKEN_H_

# define	TYPE	"|&;<>"

# define	CMD	(WORD | O_RLEFT | O_RDLEFT | O_RRIGHT | O_RDRIGHT)

# define	SEP	" \t\n"

# include	"my_typedef.h"

typedef	struct	s_token	t_token;

typedef	enum	s_type
  {
    WORD = 1,
    O_OR = WORD * 2,
    O_AND = O_OR * 2,
    O_COMMA = O_AND * 2,
    O_PIPE = O_COMMA * 2,
    O_RLEFT = O_PIPE * 2,
    O_RDLEFT = O_RLEFT * 2,
    O_RRIGHT = O_RDLEFT * 2,
    O_RDRIGHT = O_RRIGHT * 2,
    NONE = 0
  }		t_type;

typedef	enum	s_priority
  {
    P_WORD = 0,
    P_O_OR = 3,
    P_O_AND = 2,
    P_O_COMMA = 1,
    P_O_PIPE = 4,
    P_O_RLEFT = 0,
    P_O_RDLEFT = 0,
    P_O_RRIGHT = 0,
    P_O_RDRIGHT = 0,
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

t_token		*my_found_token(t_token *token, t_type type);

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

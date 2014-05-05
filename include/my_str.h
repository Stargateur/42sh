/*
** my_str.h for my_str in /home/plasko_a/rendu/prog_elem
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Fri Apr 25 03:16:39 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:16:40 2014 Antoine Plaskowski
*/

#ifndef		MY_STR_H_
# define	MY_STR_H_

# define	BUF	4048

# include	"my_typedef.h"

typedef	struct	s_str t_str;

struct		s_str
{
  t_str		*prev;
  char		*str;
  t_str		*next;
};

int		my_putchar(const char c, const int fd);

int		my_putstr(const char *str, const int fd);

t_uint		my_strlen(const char *str);

int		my_putnbr(int nb, const int fd);

int		my_putnbr_base(int nb, const char *base, const int fd);

int		my_strcpy(char *dest, const char *src);

int		my_strncpy(char *dest, const char *src, t_uint n);

int		my_getnbr(const char *str);

int		my_getnbr_base(const char *str, const char *base);

int		my_sign_nbr(const char *str);

int		my_is_num(const char *str);

char		*my_strdup(const char *str);

char		*my_strndup(const char *str, t_uint n);

char		*my_strcat(const char *str1, const char *str2);

int		my_strcmp(const char *s1, const char *s2);

int		my_strncmp(const char *s1, const char *s2, const int n);

int		my_char_in_str(const char c, const char *str);

char		*my_epur_str(char *str);

char		*my_get_next_line(const int fd);

char		**my_str_to_tab(const char *str, const char *delim);

/*
**		my_malloc.c
*/

void		*my_malloc(t_uint size_octet);

void		*my_calloc(t_uint size_octet);

/*
**		my_str.c
*/

t_str		*my_put_str(t_str *old, char *str);

t_str		*my_first_elem_str(t_str *str);

void		my_free_str(t_str *str);

void		my_free_all_str(t_str *str);

int		my_aff_str(t_str *str);

/*
**		my_put_error.c
*/

int		my_put_error(char *str);

void		*my_put_error_null(char *str);

/*
**		my_tab.c
*/

void		my_free_tab(char **tab);

char		**my_cpy_tab(char **tab);

t_uint		my_len_tab(char **tab);

int		my_aff_tab(char **tab, const int fd);

#endif		/* !MY_STR_ */

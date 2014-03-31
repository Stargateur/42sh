/*
** my_str.h for my_str in /home/plasko_a/rendu/PSU_2013_minishell1/header
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Dec 14 23:00:22 2013 Antoine Plaskowski
** Last update Thu Feb 20 00:39:17 2014 Antoine Plaskowski
*/

#ifndef		MY_STR_H_
# define	MY_STR_H_

# include	<stdlib.h>

int		my_putchar(const char c, const int fd);
int		my_putstr(const char *str, const int fd);
size_t		my_strlen(const char *str);
int		my_strcpy(char *dest, const char *src);
int		my_strncpy(char *dest, const char *src, int n);
int		my_getnbr(const char *str);
char		*my_strdup(const char *str);
char		*my_strndup(const char *str, int n);
char		*my_strcat(const char *str1, const char *str2);
int		my_strcmp(const char *s1, const char *s2);
int		my_strncmp(const char *s1, const char *s2, const int n);
int		my_char_in_str(const char c, const char *str);

/*
** my_str_to_wordtab.c
*/

char		**my_str_to_wordtab(const char *str);
int		my_free_wordtab(char **tab);
int		my_aff_wordtab(char **tab);

void		*my_malloc(size_t size_octect);

#endif		/* MY_STR_ */

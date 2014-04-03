/*
** my.h for my.h in /home/costa_b/rendu/Piscine-C-include
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Oct 21 09:38:17 2013 Kevin Costa
** Last update Fri Mar  7 18:15:23 2014 Kevin Costa
*/

#ifndef		MY_H_
# define	MY_H_
# define        MEM_SIZE 4048

void		my_putchar(char c);
int		my_put_nbr(int nb);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		overflow(char *str, char *ref);
int             minishell2(char **env);
char		*get_next_line(const int fd);
char            *my_strcpy(char *dest, char *src);
char		*my_strtabcpy(char **dest, char **src);
int             my_strcmp(char *s1, char *s2);
char            *my_strdup(char *src);
void             my_put_error(char *str);
void		check_exit(char *buffer);
int		my_exec(char **wordtab,char **env, char **path);
int		my_cmd(char **wordtab, char **env, char **path);
int		my_nb_word(char *str);
int		my_nb_letter(char *str);
char		**my_str_to_wordtab(char *str);
char		**cpy_env(char **env);
char		**my_path(char **env);
int             my_nb_pathword(char *str);
int             my_nb_pathletter(char *str);
char            **my_str_to_pathtab(char *str);
char            *my_add_str(char *str, char *str2);
void            my_execlp(char *name, char *path, char **wordtab, char **env);
int		check_buffer(char *buffer);

#endif

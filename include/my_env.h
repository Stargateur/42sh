/*
** my_env.h for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/include
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:18:01 2014 Pierrick Gicquelais
** Last update Thu May 22 16:34:18 2014 Pierrick Gicquelais
*/

#ifndef		MY_ENV_H_
# define	MY_ENV_H_

# include	"my_typedef.h"

typedef	struct	s_env	t_env;

struct		s_env
{
  t_env		*prev;
  t_env		*next;
  char		*name;
  char		*value;
};

t_env		*my_new_env(void);
t_env		*my_first_env(t_env *env);
t_env		*my_last_env(t_env *env);
t_env		*my_copy_env(char **env_tab);
t_env		*my_append_env(t_env *env, char *name, char *value);
t_env		*my_add_env(t_env *env, char *name, char *value);
t_env		*my_found_env(t_env *env, char *name);
t_env		*my_sup_env(t_env *, char *);
int		my_aff_all_env(t_env *env, const int fd);
int		my_aff_env(t_env *env, const int fd);
void		my_free_env(t_env *env);
void		my_free_all_env(t_env *env);
t_uint		my_len_env(t_env *env);
char		**my_env_to_tab(t_env *env);

#endif		/* !MY_ENV_H_ */

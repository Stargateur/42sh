/*
** my_env.h for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/include
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:18:01 2014 Pierrick Gicquelais
** Last update Mon May 12 10:31:48 2014 Pierrick Gicquelais
*/

#ifndef		MY_ENV_H_
# define	MY_ENV_H_

typedef struct	s_env	t_env;

struct		s_env
{
  t_env		*prev;
  t_env		*next;
  char		*name;
};

t_env		*my_env(char **);
t_env		*my_new_env();
t_env		*my_first_env(t_env *);
t_env		*my_last_env(t_env *);
t_env		*my_append_env(t_env *, char *);
void		my_aff_all_env(t_env *, const int);
void		my_aff_env(t_env *, const int);
void		my_free_env(t_env *);
void		my_free_all_env(t_env *);

#endif		/* !MY_ENV_H_ */

/*
** my_pwd.h for my_pwd in /home/plasko_a/rendu/pwd
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Dec 21 19:29:13 2013 Antoine Plaskowski
** Last update Sun Feb 23 09:11:54 2014 Antoine Plaskowski
*/

#ifndef		MY_PWD_H_
# define	MY_PWD_H_

typedef struct	s_list t_list;
struct		s_list
{
  struct s_list	*next;
  char		*str;
};

char		*my_pwd(void);

#endif		/* !MY_PWD_H_ */

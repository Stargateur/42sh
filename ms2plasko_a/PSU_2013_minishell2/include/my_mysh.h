/*
** my_mysh.h for my_mysh in /home/plasko_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb 19 14:13:30 2014 Antoine Plaskowski
** Last update Sun Feb 23 07:37:40 2014 Antoine Plaskowski
*/

#ifndef		MY_MYSH_H_
# define	MY_MYSH_H_

#include	"my_struct_cmd.h"

typedef struct	s_mysh t_mysh;
struct		s_mysh
{
  t_cmd		*cmd;
  char		**env;
};

#endif		/* !MY_MYSH_H_ */

/*
** my_exec.h for my_exec in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 14:50:34 2014 Antoine Plaskowski
** Last update Tue May 13 13:51:19 2014 Pierrick Gicquelais
*/

#ifndef		MY_EXEC_H_
# define	MY_EXEC_H_

# include	"my_btree.h"

int		my_exec(t_btree *, char **);
int		my_cmd(t_btree *, char **);
int		my_redirection(char *, int);
int		my_sright_redirection(char *);
int		my_dright_redirection(char *);
int		my_sleft_redirection(char *);
int		my_dleft_redirection(char *);

#endif		/* !MY_EXEC_H_ */

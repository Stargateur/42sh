/*
** my_redirection.h for my_redirection in /home/plasko_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Feb 24 15:04:14 2014 Antoine Plaskowski
** Last update Sun Mar  9 20:15:24 2014 Antoine Plaskowski
*/

#ifndef		MY_REDIRECTION_H_
# define	MY_REDIRECTION_H_

# include	"my_struct_cmd.h"

int		my_redir_left_simple(t_cmd *cmd);
int		my_redir_left_double(t_cmd *cmd);
int		my_redir_right_simple(t_cmd *cmd);
int		my_redir_right_double(t_cmd *cmd);
int		my_redir(t_cmd *cmd);

int		my_help_redir_left_double(t_cmd *cmd, int fd_pipe[2]);

#endif		/* !MY_REDIRECTION_H_ */

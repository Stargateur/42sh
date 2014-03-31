/*
** my_struct_cmd.h for my_struct_cmd in /home/plasko_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb 19 14:23:58 2014 Antoine Plaskowski
** Last update Sun Mar  9 20:28:10 2014 Antoine Plaskowski
*/

#ifndef		MY_STRUCT_CMD_H_
# define	MY_STRUCT_CMD_H_

typedef struct	s_cmd t_cmd;
struct		s_cmd
{
  t_cmd		*prev;
  char		**argv;
  char		*exe;
  char		*dleft;
  char		*left;
  char		*dright;
  char		*right;
  t_cmd		*pipe;
  t_cmd		*coma;
};

t_cmd		*my_create_cmd(char **env, char *input);
void		my_free_cmd(t_cmd *cmd);

#endif		/* !MY_STRUCT_CMD_H_ */

/*
** my_shell.h for my_shell in /home/plasko_a/programation/epitech/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 22:09:47 2014 Antoine Plaskowski
** Last update Sat May 24 13:07:24 2014 Antoine Plaskowski
*/

#ifndef		MY_SHELL_H_
# define	MY_SHELL_H_

# include	"my_env.h"
# include	"my_token.h"

typedef	struct	s_fd	t_fd;
typedef	struct	s_shell	t_shell;
typedef	struct	s_fbuil	t_fbuil;

struct		s_shell
{
  t_env		*env;
  int		exit_value;
  char		exit;
  char		exit_print;
};

struct		s_fd
{
  int		fd_0;
  int		fd_1;
  int		fd_pipe[2];
  int		fd_redir[2];
};

struct		s_fbuil
{
  int		(*fct)(t_shell *shell, t_fd *fd, char **argv);
  char		*name;
};

int		my_shell(t_shell *shell, char **env_tab);

int		my_exit(t_shell *shell, t_fd *fd, char **argv);

int		my_env(t_shell *shell, t_fd *fd, char **argv);

int		my_setenv(t_shell *shell, t_fd *fd, char **argv);

int		my_unsetenv(t_shell *shell, t_fd *fd, char **argv);

int		my_echo(t_shell *shell, t_fd *fd, char **argv);

int		my_cd(t_shell *shell, t_fd *fd, char **argv);

int		my_check_builtin(t_token *token);

int		my_builtin(t_shell *shell, t_token *token, t_fd *fd);

#endif		/* !MY_SHELL_H_ */

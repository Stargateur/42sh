/*
** my_echo.h for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/include
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 23 16:52:02 2014 Pierrick Gicquelais
** Last update Sun May 25 20:31:02 2014 Antoine Plaskowski
*/

#ifndef		MY_ECHO_H_
# define	MY_ECHO_H_

# include	"my_shell.h"

# define	OK		1
# define	FAIL		-1

# define	OPT_N		"-n"
# define	OPT_P_E		"-e"
# define	OPT_G_E		"-E"

# define	READ_MAX	64
# define	BUFFER		100

typedef	struct	s_echo
{
  int		t_e;
  int		t_n;
  int		start;
}		t_echo;

int	check_slash(char **, t_echo *);

char	*get_next_line(const int);

void	get_opt(char *,  t_echo *);

int	my_get_flag(char *, t_echo *, int);

int	my_check_echo(char **,  t_echo *);

int	norm_echo(char **, t_echo *, int);

void	my_err_mall(char *);

int	my_put_nbr(int );

void	my_free(char **);

#endif		/* !MY_ECHO_H_ */

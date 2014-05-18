/*
** my.h for my.h in /home/marsil_g/Documents/PSU/PSU-MS1/MS
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Thu Dec 19 22:08:23 2013 Gabriele Marsili
** Last update Sun May 18 23:39:28 2014 Gabriele Marsili
*/

#ifndef		__INCLUDES_H__
# define	__INCLUDES_H__

# include	<stdarg.h>

# define	OK		1
# define	FAIL		-1

# define	OPT_N		"-n"
# define	OPT_P_E		"-e"
# define	OPT_G_E		"-E"

# define	READ_MAX	64
# define	BUFFER		100

typedef struct	s_echo
{
  int		t_e;
  int		t_n;
  int		start;
}		t_echo;


char	*get_next_line(const int);

void	get_opt(char *,  t_echo *);

void	my_fputchar(int, char );

void	my_echo();

int	my_get_flag(char *, t_echo *, int);

int	my_check_echo(char **,  t_echo *);

void	norm_echo(char **, t_echo *);

char	*epur_str(char *);

void	my_err_mall(char *);

char	**my_str_to_wordtab(char *);

int	my_fputstr(int, char *);

int	my_strlen(char *);

int	my_put_nbr(int );

char	*my_strcat(char *, char *);

int	my_strcmp(char *, char *);

int	my_getnbr(char *);

void	my_free(char **);

#endif

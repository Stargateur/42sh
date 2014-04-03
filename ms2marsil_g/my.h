/*
** my.h for my.h in /home/marsil_g/Documents/PSU/PSU-MS1/MS
** 
** Made by Gabriele Marsili
** Login   <marsil_g@epitech.net>
** 
** Started on  Thu Dec 19 22:08:23 2013 Gabriele Marsili
** Last update Sat Mar  8 16:00:56 2014 marsil_g
*/

#ifndef		__MY_H__
# define	__MY_H__

# define	READ_MAX	256
# define	BUFFER		100

char	*get_next_line(const int);
void	my_putchar(char);
void	my_putstr(char *);
void	comm_exec(char **, char **);
int	my_strlen(char *);
char	**my_path_to_wordtab(char *);
char	**boucle(char *, char **, int , int );
char	**norm_str_to_wordtab(char *);
char	**norm_boucle(char *, char **, int , int );
int	n_mots(char *);
int	my_put_nbr(int );
char	**env_cpy(char **);
char	*my_strcat(char *, char *);
pid_t	my_wait(char **, char **, char **, char *);
void	my_exec(char **, char **, char **);
int	my_exit(char **, char **, char **, char *);
int	my_cd(char **, char **);
void	cd_vide(char **);
void	my_err_mall(char *);
void	my_error(char *);
int	my_strcmp(char *, char *);
int	my_getnbr(char *);
char	*get_home(char *);
char	*get_path(char **);
void	init_all(char **);
void	free_all(char **, char **, char **);
void	free1(char **, char **);
void	free_tab(char **);
void	free_pth(char **);
void	free_env(char **);
char	*epur_str(char *);
int	check_space(char*);

#endif

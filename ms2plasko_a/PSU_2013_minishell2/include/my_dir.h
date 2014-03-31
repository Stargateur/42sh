/*
** my_dir.h for my_dir in /home/plasko_a/rendu/PSU_2013_my_ls/header
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Nov 29 18:20:57 2013 Antoine Plaskowski
** Last update Sat Dec 21 21:49:15 2013 Antoine Plaskowski
*/

#ifndef		MY_DIR_H_
# define	MY_DIR_H_

# include	<dirent.h>

int		my_chdir(const char *path);
DIR		*my_open_dir(const char *path);
int		my_close_dir(DIR *dir);
char		*my_cat_dir(const char *dir, const char *name);

#endif		/* !MY_DIR_H_ */

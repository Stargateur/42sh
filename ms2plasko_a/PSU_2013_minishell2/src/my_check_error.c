/*
** my_check_error.c for my_check_error in /home/plasko_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Mar  9 09:59:53 2014 Antoine Plaskowski
** Last update Sun Mar  9 20:56:15 2014 Antoine Plaskowski
*/

#include	<unistd.h>
#include	<sys/stat.h>
#include	"my_str.h"

int		my_check_exe(char *exe)
{
  struct stat	st;

  if (stat(exe, &st))
    {
      my_putstr(exe, 2);
      my_putstr(" : can't find\n", 2);
      return (1);
    }
  if (access(exe, X_OK))
    {
      my_putstr(exe, 2);
      my_putstr(" : no permition to exe\n", 2);
      return (1);
    }
  if (st.st_mode & __S_IFDIR)
    {
      my_putstr(exe, 2);
      my_putstr(" is a directory\n", 2);
      return (1);
    }
  return (0);
}

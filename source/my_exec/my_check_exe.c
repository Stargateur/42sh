/*
** my_check_exe.c for my_check_exe in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_exec
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Sat May 24 13:32:56 2014 Antoine Plaskowski
** Last update Sat May 24 13:43:57 2014 Antoine Plaskowski
*/

#include	<unistd.h>
#include	<sys/stat.h>
#include	"my_str.h"

int		my_check_exe(char *exe)
{
  struct stat	st;

  if (exe == NULL)
    return (1);
  if (stat(exe, &st))
    {
      my_putstr(exe, 2);
      my_putstr(" : can't find\n", 2);
      return (1);
    }
  if (access(exe, X_OK))
    {
      my_putstr(exe, 2);
      my_putstr(" : isn't a exe\n", 2);
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

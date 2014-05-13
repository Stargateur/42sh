/*
** my_check_overflow_int.c for my_check_overflow_int in /home/plasko_a/rendu/epic_js_fantasy/source/my_str
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Sat May 10 21:51:01 2014 Antoine Plaskowski
** Last update Sat May 10 22:00:08 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_check_overflow_int(const char *str)
{
  t_uint	i;

  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  if (i > my_strlen("2147483647"))
    return (my_put_error("Warning overflow\n"));
  else if (i == my_strlen("2147483647"))
    {
      if (my_sign_nbr(str) == 1)
	{
	  if (my_strncmp(str, "2147483647", i) > 0)
	    return (my_put_error("Warning overflow\n"));
	}
      else
	{
	  if (my_strncmp(str, "2147483648", i) > 0)
	    return (my_put_error("Warning overflow\n"));
	}
    }
  return (0);
}

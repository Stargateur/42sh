/*
** msbis.c for msbis in /home/marsil_g/Documents/PSU/PSU-MS1/MS
**
** Made by marsil_g
** Login   <marsil_g@epitech.net>
**
** Started on  Mon Mar  3 17:20:28 2014 marsil_g
** Last update Sat Mar  8 16:11:18 2014 marsil_g
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

void		comm_exec(char **pth, char **my_env)
{
  pid_t		pid;
  char		*s;
  char		**tab;

  while (((s = get_next_line(0)) != NULL))
    {
      if (s[0] != '\0' && check_space(s) == 1)
      	{
	  tab = norm_str_to_wordtab(epur_str(s));
	  pid = my_wait(tab, my_env, pth, s);
	  if (pid == -1)
	    my_putstr("Fork error\n");
	  else if (pid == 0)
	    if (my_cd(tab, my_env) == 0 && my_exit(tab, my_env, pth, s) == 0)
	      my_exec(pth, my_env, tab);
	  free_tab(tab);
	  free(s);
	}
      my_putstr("$> ");
    }
  free1(pth, my_env);
}


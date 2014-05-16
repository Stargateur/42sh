/* PAS D HEADER  */

#include	<stdlib.h>

void		my_putchar(char c)
{
  write (1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
} 
int		my_strcmp(char *str, char *str1)
{
  int		i;
  
  if (str == NULL || str1 == NULL)
      return (-1);
    i = 0;
    while (str[i] == str1[i] && str[i] != '\0')
      i++;
    return (!(str[i] == str1[i]));
}

int		count_args(char **av)
{
  int		i;

  i = 0;
  while (av[i])
    i++;
  return (i);
}

void		aff_echo(int start, int end, char **av)
{
  int		i;

  i = start;
  while (i < end)
    {
      write(1, av[i], my_strlen(av[i]));
      if (i + 1 < end)
	my_putchar(' ');
    }
}

int		my_echo(char **av)
{
  int		ac;

  ac = count_args(av);
  if (ac >= 3)
    {
      if (!my_strcmp(av[1], "-n"))
	aff_echo(2, ac, av);
      else
	{
	  aff_echo(1, ac, av);
	  my_putchar('\n');
	}
    }
  else if (ac == 2)
    {
      if (my_strcmp(av[1], "-n"))
	{
	  write(1, av[1], my_strlen(av[1]));
	  my_putchar('\n');
	}
    }
  return (0);
}

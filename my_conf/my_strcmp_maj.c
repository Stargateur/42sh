/*
** my_strcmp_maj.c for 42sh in /home/makusa_n/depot_git/PSU_2013_42sh/my_conf
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Fri May 16 15:13:03 2014 Nayden Makusa
** Last update Fri May 16 15:24:16 2014 Nayden Makusa
*/

int		my_strcmp_maj(char *s1, char *s2)
{
  int		a;

  a = 0;
  while (s1[a] != '\0' || s2[a] != '\0')
    {
      if (s1[a] != s2[a] && s1[a] != (s2[a] - 32))
	return (1);
      a++;
    }
  return (0);
}

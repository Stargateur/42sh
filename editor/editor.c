/*
** editor.c for editor in /home/costa_b/rendu/42sh/PSU_2013_42sh/editor
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Wed May 28 17:44:57 2014 Kevin Costa
** Last update Wed May 28 18:06:43 2014 Kevin Costa
*/

#include	<stdlib.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  while (*str)
    my_putchar(*str++);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

/* TU VA DEVOIR FAIRE DES LISTES CHAINEE FUIS COSTA FUIS */

char		*editor(char *str) /* ajoute la touche minilibx */
{
  char		*tab;
  int		i;

  i = 0;
  if (str == NULL)
    return (NULL);
  if ((tab = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  while(str[i])
    {
      /* tu dois rajouter les touche gauche et droite lorsque tu écris  */
      tab[i] = str[i++];
    }
  return (tab);
}

int		main(int ac, char **av)
{
  char		*tab;

  if ((tab = editor(av[1])) == NULL)
    return (0);
  my_putstr(tab);
}

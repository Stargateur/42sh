/*
** get_next_line.c for sudoki-bi in /home/makusa_n/depot_git/sudoki-bi
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Sat Mar  1 13:01:54 2014 Nayden Makusa
** Last update Fri May 16 16:29:05 2014 Nayden Makusa
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"get_next_line.h"

static t_list	*add_in_list(t_list *my_list, char c)
{
  t_list	*new_element;
  t_list	*tmp;

  new_element = malloc(sizeof(t_list));
  new_element->c = c;
  new_element->next = NULL;
  if (my_list == NULL)
    return (new_element);
  tmp = my_list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_element;
  return (my_list);
}

static int	check_list(t_list *my_list)
{
  t_list	*tmp;

  tmp = my_list;
  while (tmp != NULL)
    {
      if (tmp->c == '\n' || tmp->c == '\0')
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

static int	str_size(t_list *my_list)
{
  t_list	*tmp;
  int		i;

  tmp = my_list;
  i = 0;
  while (tmp != NULL)
    {
      if (tmp->c == '\n' || tmp->c == '\0')
	return (i);
      tmp = tmp->next;
      i++;
    }
  return (i);
}

static char	*list_to_str(t_list **my_list)
{
  t_list	*ptr;
  char		*str;
  int		i;

  i = 0;
  if ((*my_list) == NULL)
    return (NULL);
  str = malloc(sizeof(char) * (str_size(*my_list) + 1));
  while ((*my_list) != NULL && (*my_list)->c != '\n' && (*my_list)->c != '\0')
    {
      ptr = (*my_list);
      str[i++] = (*my_list)->c;
      (*my_list) = (*my_list)->next;
      free(ptr);
    }
  str[i] = '\0';
  if ((*my_list) != NULL)
    {
      ptr = (*my_list);
      (*my_list) = (*my_list)->next;
      free(ptr);
    }
  return (str);
}

extern char	*get_next_line(const int fd)
{
  static t_list	*my_list;
  char		buffer[BUFF_SIZE];
  int		val;
  int		i;

  i = 0;
  while (i < BUFF_SIZE)
    buffer[i++] = 0;
  if ((val = read(fd, buffer, BUFF_SIZE)) < 0)
    return (NULL);
  if (val == 0)
    return (list_to_str(&my_list));
  i = 0;
  while (i < val)
    my_list = add_in_list(my_list, buffer[i++]);
  if (check_list(my_list))
    return (list_to_str(&my_list));
  return (get_next_line(fd));
}

/*
** my.h for 42sh in /home/makusa_n/depot_git/PSU_2013_42sh/source/my_conf
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Thu May 29 19:53:00 2014 Nayden Makusa
** Last update Thu May 29 20:12:26 2014 Nayden Makusa
*/

typedef struct		element element;
struct element
{
  char			*val;
  struct element	*next;
};

typedef element*	list;

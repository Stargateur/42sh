/*
** my_strcat.c for my_strcat in /home/plasko_a/rendu/PSU_2013_minishell1/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Dec 21 20:58:32 2013 Antoine Plaskowski
** Last update Tue May 13 18:04:02 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

char		*my_strcat(const char *str1, const char *str2)
{
  char		*str;
  t_uint	i;

  i = my_strlen(str1) + my_strlen(str2) + 1;
  if ((str = my_malloc(sizeof(char) * i)) == NULL)
    return (NULL);
  i = 0;
  if (str1 != NULL)
    while (*str1 != '\0')
      str[i++] = *str1++;
  if (str2 != NULL)
    while (*str2 != '\0')
      str[i++] = *str2++;
  str[i] = '\0';
  return (str);
}

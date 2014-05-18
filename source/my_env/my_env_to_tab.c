/*
** my_env_to_tab.c for my_env_to_tab in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_env
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 18 22:23:49 2014 Antoine Plaskowski
** Last update Sun May 18 22:50:37 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_env.h"
#include	"my_str.h"

static char	*my_env_to_str(char *name, char *value)
{
  char		*str;
  t_uint	i;

  i = my_strlen(name) + my_strlen(value) + 2;
  if ((str = my_malloc(sizeof(char) * i)) == NULL)
    return (NULL);
  i = 0;
  if (name != NULL)
    while (*name != '\0')
      str[i++] = *name++;
  str[i++] = '=';
  if (value != NULL)
    while (*value != '\0')
      str[i++] = *value++;
  str[i] = '\0';
  return (str);
}

char		**my_env_to_tab(t_env *env)
{
  char		**env_tab;
  t_uint	i;

  if ((env = my_first_env(env)) == NULL)
    return (NULL);
  if ((env_tab = my_malloc(sizeof(char *) * (my_len_env(env) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (env != NULL)
    {
      env_tab[i++] = my_env_to_str(env->name, env->value);
      env = env->next;
    }
  env_tab[i] = NULL;
  return (env_tab);
}

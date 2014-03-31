/*
** my_tool_env.h for my_tool_env in /home/plasko_a/rendu/PSU_2013_minishell1/header
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec 15 18:24:40 2013 Antoine Plaskowski
** Last update Sun Feb 23 09:40:08 2014 Antoine Plaskowski
*/

#ifndef		MY_TOOL_ENV_H_
# define	MY_TOOL_ENV_H_

char		*my_var_env(char **env, const char *str);
int		my_found_env(char **env, const char *str);
int		my_search_env(char **env, const char *name);
int		my_len_name_env(const char *str);

#endif		/* !MY_TOOL_ENV_H_ */

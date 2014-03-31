/*
** main.c for main in /home/plasko_a/rendu/PSU_2013_minishell1/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Dec 14 22:53:16 2013 Antoine Plaskowski
** Last update Sun Mar  9 21:18:29 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<signal.h>
#include	"my_get_next_line.h"
#include	"my_struct_cmd.h"
#include	"my_tool_tab.h"
#include	"my_management.h"
#include	"my_mysh.h"
#include	"my_str.h"

static int	interup_signal = 0;

static void	my_signal_sigint(int status)
{
  if (status != SIGINT)
    my_putstr("error in gestion signal...\n", 2);
  if ((signal(SIGINT, &my_signal_sigint)) == SIG_ERR)
    my_putstr("can't set ignore sigint\n", 2);
  interup_signal = 1;
  my_putchar('\n', 1);
}

static void	my_signal_sigtstp(int status)
{
  if (status != SIGTSTP)
    my_putstr("error in gestion signal...\n", 2);
  if ((signal(SIGTSTP, &my_signal_sigtstp)) == SIG_ERR)
    my_putstr("can't set ignore sigstop\n", 2);
  interup_signal = 1;
  my_putchar('\n', 1);
}

static int	my_init_mysh(t_mysh *mysh, char **env)
{
  if (mysh == NULL)
    return (1);
  if ((signal(SIGINT, &my_signal_sigint)) == SIG_ERR)
    my_putstr("can't set ignore sigint\n", 2);
  if ((signal(SIGTSTP, &my_signal_sigtstp)) == SIG_ERR)
    my_putstr("can't set ignore sigstop\n", 2);
  mysh->cmd = NULL;
  if ((mysh->env = my_cpy_tab(env)) == NULL)
    return (1);
  return (0);
}

static int	my_get_input(t_mysh *mysh)
{
  char		*input;

  if (mysh == NULL)
    return (0);
  mysh->cmd = NULL;
  if ((input = my_get_next_line(0)) != NULL)
    {
      mysh->cmd = my_create_cmd(mysh->env, input);
      free(input);
    }
  else
    return (0);
  return (1);
}

int		main(int argc, char **argv, char **env)
{
  t_mysh	mysh;

  argv[argc] = NULL;
  if (my_init_mysh(&mysh, env))
    return (1);
  my_putstr("$>", 1);
  while (my_get_input(&mysh) || interup_signal)
    {
      interup_signal = 0;
      my_management(&mysh);
      my_free_cmd(mysh.cmd);
      my_putstr("$>", 1);
    }
  my_free_tab(mysh.env);
  my_putchar('\n', 1);
  return (0);
}

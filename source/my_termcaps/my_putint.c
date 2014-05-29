/*
** my_putint.c for my_putint.c in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Jan 15 14:46:08 2014 Antoine PLASKOWSKI
** Last update Thu May 29 14:21:48 2014 Antoine Plaskowski
*/

#include	<unistd.h>

int		my_putint(const int nb)
{
  return (write(0, &nb, 1) != 1);
}

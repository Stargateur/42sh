/*
** my_msg_check_file.c for 42sh in /home/makusa_n/depot_git/my_conf
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Thu May 29 12:56:05 2014 Nayden Makusa
** Last update Thu May 29 22:14:34 2014 Nayden Makusa
*/

int		my_check_order_flag_message(int verif, int mul_alias,
					    int mul_end, int mul_prompt)
{
  if (verif != 3)
    {
      my_putstr("Error: You must write 'alias' then 'end' and 'prompt' ");
      my_putstr(" after in the conf file.\n");
      return (1);
    }
  if (mul_alias != 1 || mul_end != 1 || mul_prompt != 1)
    {
      if (mul_alias != 1)
	my_putstr("Multiple declaration of 'alias' int the conf file.\n");
      if (mul_end != 1)
	my_putstr("Multiple declaration of 'end' int the conf file.\n");
      if (mul_prompt != 1)
	my_putstr("Multiple declaration of 'prompt' int the conf file.\n");
      return (1);
    }
  return (0);
}

int		my_check_flag_message(int verif_prompt, int verif_alias,
				      int verif_end, int verif_empty)
{
  if (verif_empty == 1)
    {
      my_putstr("Error: there is an empty string in the conf file.\n");
      return (1);
    }
  if (verif_prompt == 1)
    {
      my_putstr("Error: there isn't the string 'prompt' in the conf file.\n");
      return (1);
    }
  if (verif_end == 1)
    {
      my_putstr("Error: there isn't the string 'end' in the conf file.\n");
      return (1);
    }
  if (verif_alias == 1)
    {
      my_putstr("Error: there isn't the string 'alias' in the conf file.\n");
      return (1);
    }
  return (0);
}

int		my_check_equal_liste_msg(int verif_equal, int verif_prompt)
{
  if (verif_equal == 1)
    {
      my_putstr("Error: there is a problem with an equal in the alias.\n");
      return (1);
    }
  if (verif_prompt == 1)
    {
      my_putstr("Error: there isn't got any prompt.\n");
      return (1);
    }
  return (0);
}

/*
** echo.c for  in /home/bedel_a/Projet/PSU/42sh
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Tue May 31 15:26:33 2016
** Last update Tue May 31 17:53:12 2016 
*/

#include "sh.h"

int		check_parentheses(char *str)
{
  int		simple_quote;
  int		double_quote;
  int		i;

  i = 0;
  simple_quote = 0;
  double_quote = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\'')
	simple_quote++;
      if (str[i] == '\"')
	double_quote++;
      i++;
    }
  if (simple_quote % 2 == 1 || double_quote % 2 == 1)
    return (-1);
  return (0);
}

int		print_arg(char *str, int idx)
{
  int		i;

  i = 0;
  if (str[0] == '$')
    return (-1);
  while (str[i] != '\0')
    {
      if (str[i] != '\'' && str[i] != '\"')
	write(1, &str[i], 1);
      i++;
    }
  if (idx == 0)
    write(1, " ", 1);
  else if (idx == 1)
    write(1, "\n", 1);
  return (0);
}

int		dollar(char *str, t_list *env, int idx, int idx_n)
{
  char		*res;

  if (str[0] == '$')
    {
      if ((res = my_getenv(env, &str[1])) == NULL)
	printf("%s: Undefined variable.\n", &str[1]);
      else if (idx == 0)
	printf("%s ", res);
      else
	{
	  if (idx_n == 1)
	    my_printf("%s", res);
	  else
	    printf("%s\n", res);
	}
      return (0);
    }
  return (-1);
}

int		do_the_rest(char **av, int idx_n, t_list *env)
{
  int		i;
  int		idx;

  i = 1;
  while (av[i + 1] != NULL)
    {
      idx = dollar(av[i], env, 0, idx_n);
      if (check_parentheses(av[i]) == 0 && idx == -1)
	print_arg(av[i], 0);
      else if (idx == -1)
	printf("Undefined quote ");
      i++;
    }
  idx = dollar(av[i], env, 1, idx_n);
  if (check_parentheses(av[i]) == 0 && idx == -1)
    print_arg(av[i], 1 + idx_n);
  else if (idx == -1)
    printf("Undefined quote\n");
  return (0);
}

int		builtins_echo(t_sh *sh)
{
  int		idx;

  idx = 0;
  if (sh->av[1] == NULL)
    return (write(1, "\n", 1));
  if (my_strcmp("-n", sh->av[1]) == 0)
    idx++;
  if (idx == 1 && sh->av[2] == NULL)
    return (-1);
  do_the_rest(&sh->av[idx], idx, sh->env);
  return (0);
}

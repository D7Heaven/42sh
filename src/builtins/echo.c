/*
1;2802;0c** echo.c for  in /home/bedel_a/Projet/PSU/42sh
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Tue May 31 15:26:33 2016
** Last update Thu Jun  2 15:11:48 2016 
*/

#include "sh.h"

int		handle_backslash(char *str, int i, int quote)
{
  char		**tab;
  int		n;

  tab = malloc(sizeof(char *) * 11);
  tab[0] = "\\\\";
  tab[1] = "a\a";
  tab[2] = "b\b";
  tab[3] = "e\e";
  tab[4] = "f\f";
  tab[5] = "n\n";
  tab[6] = "r\r";
  tab[7] = "t\t";
  tab[8] = "v\v";
  tab[9] = NULL;
  n = -1;
  while (tab[++n] != NULL)
    {
      if (str[i + 1] == tab[n][0] && quote == 1)
	return (write(1, &tab[n][1], 1));
    }
  if (quote == 1)
    write(1, "\\", 1);
  if (str[i] != '\"')
    write(1, &str[i + 1], 1);
  return (0);
}

int		print_arg(char *str, int idx, int quote)
{
  int		i;

  i = 0;
  if (str[0] == '$')
    return (-1);
  while (str[i] != '\0')
    {
      if (str[i] != '\'' && str[i] != '\"')
	{
	  if (str[i] == '\\')
	    {
	      handle_backslash(str, i, quote);
	      i++;
	    }
	  else if (str[i] != '\\')
	    write(1, &str[i], 1);
	}
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
  int		quote;

  i = 1;
  while (av[i + 1] != NULL)
    {
      idx = dollar(av[i], env, 0, idx_n);
      quote = check_parentheses(av[i]);
      if (quote != -1 && idx == -1)
	print_arg(av[i], 0, quote);
      else if (idx == -1)
	printf("Undefined quote ");
      i++;
    }
  idx = dollar(av[i], env, 1, idx_n);
  quote = check_parentheses(av[i]);
  if (check_parentheses(av[i]) != -1 && idx == -1)
    print_arg(av[i], 1 + idx_n, quote);
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

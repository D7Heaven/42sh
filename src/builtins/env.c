/*
** env.c for  in /home/bedel_a/Projet/PSU/42sh/src/builtins
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Mon May 30 17:36:38 2016
** Last update Tue Jun  7 18:18:55 2016 
*/

#include "sh.h"

int	builtins_env(t_sh *sh)
{
  print_list(sh->env);
  return (0);
}

int     builtins_setenv(t_sh *sh)
{
  if (sh->av[1] != NULL)
    my_setenv(&sh->env, sh->av[1], sh->av[2]);
  else
    print_list(sh->env);
  return (0);
}

int	builtins_unsetenv(t_sh *sh)
{
  int   i;

  i = 1;
  if (sh->av[1] != NULL)
    {
      while (sh->av[i] != NULL)
        {
          my_unsetenv(&sh->env, sh->av[i], sh);
          i++;
	}
    }
  else
    my_printf("unsetenv [key]\n");
  return (0);
}

int	is_it_ok(char *str)
{
  int	i;

  if (!((str[0] >= 'a' && str[0] <= 'z') ||
	(str[0] >= 'A' && str[0] <= 'Z')))
    return (-1);
  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] == '.' ||
	    ((str[i] >= 'a' && str[i] <= 'z') ||
	     (str[i] >= 'A' && str[i] <= 'Z')) ||
	    (str[i] >= '0' && str[i] <= '9')))
	return (-1);
      i++;
    }
  return (1);
}

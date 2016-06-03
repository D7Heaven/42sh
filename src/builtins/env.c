/*
** env.c for  in /home/bedel_a/Projet/PSU/42sh/src/builtins
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Mon May 30 17:36:38 2016
** Last update Fri Jun  3 13:48:36 2016 Jean Jonathan
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

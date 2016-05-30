/*
** env.c for  in /home/bedel_a/Projet/PSU/42sh/src/builtins
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Mon May 30 17:36:38 2016
** Last update Mon May 30 17:49:12 2016 
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
  if (sh->av[1] != NULL)
    my_unsetenv(&sh->env, sh->av[1], sh);
  else
    my_printf("unsetenv [key]\n");
  return (0);
}

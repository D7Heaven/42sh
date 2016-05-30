/*
** helper2.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell2
**
** Made by Jean Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Tue Apr 12 14:33:45 2016 Jean Jonathan
** Last update Tue Apr 12 15:14:32 2016 Jean Jonathan
*/

#include "sh.h"
#include "my.h"

char    **fill_ops()
{
  char  **ops;

  if ((ops = malloc(sizeof(char *) * MAX_OPS)) == NULL)
    return (NULL);
  ops[0] = my_strdup(";");
  ops[1] = my_strdup(">>");
  ops[2] = my_strdup(">");
  ops[3] = my_strdup("|");
  ops[4] = my_strdup("<");
  return (ops);
}

void    print_prompt(t_sh *sh)
{
  my_putstr("$");
  my_putstr(my_getenv(sh->env, "PWD"));
  my_putstr("> ");
}

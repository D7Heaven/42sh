/*
** builtins2.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell1
**
** Made by Jean Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Sun Jan 31 21:18:18 2016 Jean Jonathan
** Last update Mon May 30 17:54:43 2016 
*/

#include "sh.h"
#include "my.h"

void    builtins_exit(t_sh *sh, int i)
{
  int code;

  if (i == 0)
    {
      if (sh->av[1] != NULL)
        code = my_ngetnbr(sh->av[1]);
      else
        code = 0;
      freetab(sh->av);
    }
  else
    code = 0;
  my_delete_list(sh->env);
  my_delete_list(sh->alias);
  free_ops(sh->ops);
  if (sh->tree != NULL)
    free_tree(sh->tree);
  my_putstr("\n");
  exit(code);
}

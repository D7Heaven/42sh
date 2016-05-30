/*
** builtins2.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell1
**
** Made by Jean Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Sun Jan 31 21:18:18 2016 Jean Jonathan
** Last update Tue Apr 12 15:26:05 2016 Jean Jonathan
*/

#include "sh.h"
#include "my.h"

t_list  *cpy_env(t_list *env, char **e)
{
  int   i;
  char  **word;

  if (e[0] == NULL)
    my_setenv(&env, "PWD", getcwd(0, 0));
  i = 0;
  while (e[i] != NULL)
    {
      word = my_cut_in_tab(e[i], '=');
      if (word == NULL)
	    return (NULL);
      my_put_in_list(&env, word[0], word[1]);
      freetab(word);
      i++;
    }
  return (env);
}

void    my_exit(t_sh *sh, int i)
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

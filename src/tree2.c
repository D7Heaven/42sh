/*
** tree2.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell2
**
** Made by Jean Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Tue Apr 12 14:37:30 2016 Jean Jonathan
** Last update Mon May 30 17:02:28 2016 Jean Jonathan
*/

#include "sh.h"
#include "my.h"

void    exec_tree(t_tree *tree, t_sh *sh)
{
  sh->actual = tree;
  sh->av = my_cut_in_tab(tree->str, ' ');
  if (my_strncmp("exit", tree->str, 4) == 0)
    builtins_exit(sh, 0);
  main_check(sh, tree->str, tree);
  if (tree->left != NULL && tree->right != NULL)
    {
      exec_tree(tree->left, sh);
      exec_tree(tree->right, sh);
    }
}

void    error_tree(t_tree *tree, t_sh *sh)
{
  if (tree->str[0] == 0)
    sh->error = 1;
  if (tree->left != NULL && tree->right != NULL)
    {
      error_tree(tree->left, sh);
      error_tree(tree->right, sh);
    }
}

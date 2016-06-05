/*
** et_ou.c for La secte in /home/arnoulr/rendu/PSU/42sh
**
** Made by Remi
** Login   <arnoulr@epitech.net>
**
** Started on  Tue May 31 14:50:28 2016 Remi
** Last update Sun Jun  5 16:31:03 2016 Remi
*/

#include "sh.h"

int		return_exec_success(t_sh *sh)
{
  if (sh->actual->parent != NULL && sh->actual == sh->actual->parent->right)
    {
    while (sh->actual != NULL && my_strcmp(sh->actual->str, "||") != 0
	 && my_strcmp(sh->actual->str, "&&") != 0)
      sh->actual = sh->actual->parent;
    if (sh->actual != NULL)
      sh->actual = sh->actual->parent;
    }
  while (sh->actual != NULL && my_strcmp(sh->actual->str, "||") != 0
	 && my_strcmp(sh->actual->str, "&&") != 0)
      sh->actual = sh->actual->parent;
  if (sh->actual != NULL)
    sh->actual->success = 1;
  return (0);
}

void		open_new_file2(t_tree *tmp, t_tree *cmd_tmp)
{
  while (my_strcmp(tmp->str, "|") == 0 || my_strcmp(tmp->str, ">") == 0 ||
	 my_strcmp(tmp->str, ">>") == 0 || my_strcmp(tmp->str, "<") == 0 ||
	 my_strcmp(tmp->str, "<<") == 0)
    tmp = tmp->left;
  while (my_strcmp(cmd_tmp->str, "|") == 0
	 || my_strcmp(cmd_tmp->str, ">") == 0 ||
	 my_strcmp(cmd_tmp->str, ">>") == 0 || my_strcmp(cmd_tmp->str, "<") == 0 ||
	 my_strcmp(cmd_tmp->str, "<<") == 0)
    cmd_tmp = cmd_tmp->right;
}

/*
** et_ou.c for La secte in /home/arnoulr/rendu/PSU/42sh
**
** Made by Remi
** Login   <arnoulr@epitech.net>
**
** Started on  Tue May 31 14:50:28 2016 Remi
** Last update Tue May 31 15:49:23 2016 Remi
*/

#include "sh.h"

int		return_exec_success(t_sh *sh)
{
  while (sh->actual != NULL && my_strcmp(sh->actual->str, "||") != 0
	 && my_strcmp(sh->actual->str, "&&") != 0)
      sh->actual = sh->actual->parent;
  if (sh->actual != NULL)
    sh->actual->success = 1;
  return (0);
}

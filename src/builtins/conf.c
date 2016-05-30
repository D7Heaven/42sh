/*
** conf.c for  in /home/bedel_a/Projet/PSU/42sh/src/builtins
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Mon May 30 17:29:17 2016
** Last update Mon May 30 17:29:36 2016 
*/

#include "sh.h"

int     builtins_reload(t_sh *sh)
{
  freetab(sh->av);
  return (load_rc(sh));
}

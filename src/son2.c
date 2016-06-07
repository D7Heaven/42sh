/*
** son2.c for 42 in /home/tonell-m/rendu/PSU/42sh
**
** Made by tonell_m
** Login   <tonell-m@epitech.net>
**
** Started on  Tue Jun  7 17:40:10 2016 tonell_m
** Last update Tue Jun  7 17:40:48 2016 tonell_m
*/

#include <errno.h>
#include "sh.h"

void			son2(t_sh *sh)
{
  my_setenv(&sh->env, "?", "1");
  printf("%s: %s.", sh->av[0], strerror(errno));
  if (errno == ENOEXEC)
    printf(" Binary file not executable.");
  printf("\n");
  builtins_exit(sh, 1);
}

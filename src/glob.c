/*
** glob.c for 42sh in /home/tonell-m/rendu/PSU/42sh
**
** Made by tonell_m
** Login   <tonell-m@epitech.net>
**
** Started on  Mon May 30 15:47:22 2016 tonell_m
** Last update Mon May 30 16:25:03 2016 tonell_m
*/

#include "sh.h"
#include "my.h"

char		*glob_path(char *arg)
{
  char		tmp;
  char		*path;
  int		i;

  i = my_strlen(arg);
  while (arg[i] != '/' && i >= 0)
    i--;
  if (i == 0)
    return (my_strdup("./"));
  tmp = arg[i + 1];
  arg[i + 1] = 0;
  path = my_strdup(arg);
  arg[i + 1] = tmp;
}

int		glob(t_sh *sh, char *path, int _av, int idx)
{
  int		cur_idx;

  cur_idx = 0;
  while (cur_idx < idx)
    {
      cur_idx++;
    }
}

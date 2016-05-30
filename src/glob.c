/*
** glob.c for 42sh in /home/tonell-m/rendu/PSU/42sh
**
** Made by tonell_m
** Login   <tonell-m@epitech.net>
**
** Started on  Mon May 30 15:47:22 2016 tonell_m
** Last update Mon May 30 17:20:03 2016 tonell_m
*/

#include "sh.h"
#include "my.h"

char		*glob_path(char *arg)
{
  char		*path;
  int		i;

  i = my_strlen(arg);
  while (arg[i] != '/' && i >= 0)
    i--;
  if (i == 0)
    return (my_strdup("."));
  arg[i] = 0;
  path = my_strdup(arg);
  arg[i] = '/';
  return (path);
}

int		glob(t_sh *sh, char *path, int _av, int idx)
{
  char		*gpath;
  DIR		*dirp;
  int		cur_idx;

  gpath = glob_path(sh->av[_av]);
  if ((dirp = opendir(gpath)) == NULL)
    {
      my_printf("%s: No such file or dirrectory\n", gpath);
      return (-1);
    }
  cur_idx = 0;
  while (cur_idx < idx)
    {

      cur_idx++;
    }
}

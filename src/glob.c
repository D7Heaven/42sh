/*
** glob.c for 42sh in /home/tonell-m/rendu/PSU/42sh
**
** Made by tonell_m
** Login   <tonell-m@epitech.net>
**
** Started on  Mon May 30 15:47:22 2016 tonell_m
** Last update Tue May 31 14:57:41 2016 tonell_m
*/

#include "sh.h"
#include "my.h"

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

int             is_glob(char *str)
{
  int           i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '*' || str[i] == '?' || str[i] == '[' || str[i] == ']')
	return (1);
      i++;
    }
  return (0);
}

int		get_gl_offs(char **av, unsigned int *ac)
{
  int		ret;

  ret = 1;
  *ac = 1;
  while (av[*ac])
    {
      if (is_glob(av[*ac]) == 0)
	ret++;
      (*ac)++;
    }
  return (ret);
}

int		globbing(t_sh *sh, char *path)
{
  int		k;
  unsigned int	ac;
  int		i;
  glob_t	globbuf;

  globbuf.gl_offs = get_gl_offs(sh->av, &ac);
  if (globbuf.gl_offs == ac)
    return (my_exec(sh, path));
  i = 1;
  while (is_glob(sh->av[i]) == 0)
    i++;
  if (glob(sh->av[i], GLOB_DOOFFS, NULL, &globbuf) != 0)
    return (printf("42sh: %s: bad pattern\n", sh->av[i]));
  while (sh->av[++i])
    if (is_glob(sh->av[i]))
      if (glob(sh->av[i], GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf) != 0)
	return (printf("42sh: %s: bad pattern\n", sh->av[i]));
  k = -1;
  i = -1;
  while (sh->av[++i])
    if (is_glob(sh->av[i]) == 0)
      globbuf.gl_pathv[++k] = my_strdup(sh->av[i]);
  free_tab(sh->av);
  sh->av = globbuf.gl_pathv;
  return (my_exec(sh, path));
}

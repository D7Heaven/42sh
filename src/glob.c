/*
** glob.c for 42sh in /home/tonell-m/rendu/PSU/42sh
**
** Made by tonell_m
** Login   <tonell-m@epitech.net>
**
** Started on  Mon May 30 15:47:22 2016 tonell_m
** Last update Fri Jun  3 15:50:54 2016 Jean Jonathan
*/

#include <errno.h>
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

int		gl_path(t_sh *sh, int i, glob_t *globbuf)
{
  int		rg;

  if ((rg = glob(sh->av[i], GLOB_DOOFFS, NULL, globbuf)) != 0)
    {
      my_setenv(&sh->env, "?", "1");
      if (rg == GLOB_NOMATCH)
	printf("%s: No match.\n", sh->av[0]);
      else
	return (2);
      return (1);
    }
  while (sh->av[++i])
    if (is_glob(sh->av[i]))
      if ((rg = glob(sh->av[i], GLOB_DOOFFS | GLOB_APPEND, NULL, globbuf)) != 0)
	{
	  my_setenv(&sh->env, "?", "1");
	  if (rg == GLOB_NOMATCH)
	    printf("%s: No match.\n", sh->av[0]);
	  else
	    return (2);
	  return (1);
	}
  return (0);
}

int		globbing(t_sh *sh, char *path)
{
  int		k;
  unsigned int	ac;
  int		i;
  glob_t	globuf;

  globuf.gl_offs = get_gl_offs(sh->av, &ac);
  if (globuf.gl_offs == ac)
    return (my_exec(sh, path));
  i = 1;
  while (is_glob(sh->av[i]) == 0)
    i++;
  if (gl_path(sh, i, &globuf) > 0)
    return (1);
  k = -1;
  i = -1;
  while (sh->av[++i])
    if (is_glob(sh->av[i]) == 0)
      globuf.gl_pathv[++k] = my_strdup(sh->av[i]);
  free_tab(sh->av);
  sh->av = globuf.gl_pathv;
  return (my_exec(sh, path));
}

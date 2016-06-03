/*
** cd.c for  in /home/bedel_a/Projet/PSU/42sh/src/builtins
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Mon May 30 17:38:09 2016
** Last update Fri Jun  3 13:57:51 2016 Jean Jonathan
*/

#include <errno.h>
#include "sh.h"

int             my_cd2(t_list **env, char *path)
{
  char          *old;

  old = getcwd(0, 0);
  if (chdir(path) == 0)
    {
      my_setenv(env, "OLDPWD", old);
      my_setenv(env, "PWD", getcwd(0, 0));
    }
  else
    {
      my_setenv(env, "?", "1");
      my_printf("%s: %s.\n", path, strerror(errno));
    }
  return (0);
}

int             my_cd(t_list **env, char *path)
{
  char          *old;

  old = getcwd(0, 0);
  if (path == NULL)
    {
      if (my_getenv(*env, "HOME") == NULL)
	return (my_printf("cd: HOME environment variable not set\n"));
      path = my_getenv(*env, "HOME");
    }
  if (path[0] == '-')
    {
      if (my_getenv(*env, "OLDPWD") != NULL)
	{
	  chdir(my_getenv(*env, "OLDPWD"));
	  my_setenv(env, "OLDPWD", old);
	  my_setenv(env, "PWD", getcwd(0, 0));
	  return (my_printf("%s\n", my_getenv(*env, "PWD")));
	}
      return (printf(": No such file or directory.\n"));
    }
  my_cd2(env, path);
  return (0);
}

int		builtins_cd(t_sh *sh)
{
  my_cd(&sh->env, sh->av[1]);
  return (0);
}

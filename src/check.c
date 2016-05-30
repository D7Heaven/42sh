/*
** check.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell1
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Fri Jan  8 16:24:15 2016 JEAN Jonathan
** Last update Mon May 30 17:28:44 2016 
*/

#include "sh.h"
#include "my.h"

int	check_here(t_sh *sh)
{
  char	*path;

  if ((access(sh->av[0], X_OK)) == 0)
    {
      if (sh->av[0][0] == '/' || sh->av[0][0] == '.')
        {
          my_exec(sh, sh->av[0]);
          return (1);
        }
      else
        return (0);
    }
  if ((path = malloc(sizeof(char) * 3 + my_strlen(sh->av[0]))) == NULL)
    return (-1);
  my_memset(path, 0, 3 + my_strlen(sh->av[0]));
  my_strcpy(path, "./");
  my_strcat(path, sh->av[0]);
  if ((access(path, X_OK)) == 0)
    {
      my_exec(sh, path);
      return (1);
    }
  return (0);
}

int     check_commands(t_sh *sh, int i, char *path, char **paths)
{
  if (check_here(sh) == 1)
    return (1);
  if (my_getenv(sh->env, "PATH") == NULL)
    return (my_printf("%s: command not found\n", sh->av[0]));
  paths = my_cut_in_tab(my_getenv(sh->env, "PATH"), ':');
  while (paths[++i] != NULL)
    {
      path = malloc(sizeof(char) * (my_strlen(paths[i])
				    + 2 + my_strlen(sh->av[0])));
      my_memset(path, 0, my_strlen(paths[i]) + 2 + my_strlen(sh->av[0]));
      if (sh->av[0][0] != '/' && sh->av[0][0] != '.')
        {
          my_strcpy(path, paths[i]);
          my_strcat(path, "/");
        }
          my_strcat(path, sh->av[0]);
      if ((access(path, X_OK)) == 0)
	{
	  freetab(paths);
	  return (my_exec(sh, path));
	}
    }
  my_printf("%s: command not found\n", sh->av[0]);
  return (freetab(sh->av));
}

int    check_builtins(t_sh *sh, char *name, t_tree *tree)
{
  if (check_ops(name, tree) == 0)
    return (0);
  if (my_strncmp("env", name, 3) == 0)
    builtins_env(sh);
  else if (my_strncmp("setenv", name, 6) == 0)
    builtins_setenv(sh);
  else if (my_strncmp("cd", name, 2) == 0)
    builtins_cd(sh);
  else if (my_strncmp("unsetenv", name, 6) == 0)
    builtins_unsetenv(sh);
  else
    return (check_builtins2(sh));
  freetab(sh->av);
  return (0);
}

int    check_builtins2(t_sh *sh)
{
  if (my_strncmp("setalias", sh->av[0], 8) == 0)
    builtins_setalias(sh);
  else if (my_strncmp("alias", sh->av[0], 5) == 0)
    builtins_alias(sh);
  else if (my_strncmp("reload", sh->av[0], 6) == 0)
    return (builtins_reload(sh));
  else if (my_strncmp("unsetalias", sh->av[0], 10) == 0)
    builtins_unsetalias(sh);
  else
    return (check_alias(sh, sh->alias, 1, 0));
  freetab(sh->av);
  return (0);
}

int		check_alias(t_sh *sh, t_list *tmp, int i, int size)
{
  char		*argv;

  while (tmp != NULL)
    {
      if (my_strcmp(sh->av[0], tmp->key) == 0)
	{
	  size += my_strlen(tmp->val) + 1;
	  while (sh->av[i] != NULL)
	    size += my_strlen(sh->av[i++]) + 1;
	  i = 1;
	  argv = malloc(sizeof(char) * size + 1);
	  my_memset(argv, 0, size + 1);
	  my_strcpy(argv, tmp->val);
	  while (sh->av[i] != NULL)
	    {
	      my_strcat(argv, " ");
	      my_strcat(argv, sh->av[i++]);
	    }
	  freetab(sh->av);
	  sh->av = my_cut_in_tab(argv, ' ');
	  return (check_commands(sh, -1, NULL, NULL));
	}
      tmp = tmp->next;
    }
  return (check_commands(sh, -1, NULL, NULL));
}

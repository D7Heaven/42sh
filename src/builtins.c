/*
** helper.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_my_select
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Thu Dec  3 16:15:13 2015 JEAN Jonathan
** Last update Tue Apr 12 15:26:32 2016 Jean Jonathan
*/

#include "sh.h"
#include "my.h"

int		my_cd2(t_list **env, char *path)
{
  struct stat	sb;
  char		*old;

  old = getcwd(0, 0);
  if (chdir(path) == 0)
    {
      my_setenv(env, "OLDPWD", old);
      my_setenv(env, "PWD", getcwd(0, 0));
    }
  else
    {
      if (stat(path, &sb) == -1)
	my_printf("%s: No such file or directory\n", path);
      else
	my_printf("%s: Not a directory\n", path);
    }
  return (0);
}

int		my_cd(t_list **env, char *path)
{
  char		*old;

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

char		*my_getenv(t_list *env, char *str)
{
  t_list	*tmp;

  tmp = env;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->key, str) == 0)
	{
	  return (tmp->val);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

int		my_setenv(t_list **env, char *key, char *val)
{
  t_list	*tmp;

  tmp = *env;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->key, key) == 0)
	{
	  free(tmp->val);
	  if (val == NULL)
	    tmp->val = NULL;
	  else
	    tmp->val = my_strdup(val);
	  return (0);
	}
      tmp = tmp->next;
    }
  my_put_in_list(env, key, val);
  return (0);
}

int		my_unsetenv(t_list **env, char *key, t_sh *sh)
{
  t_list	*tmp;

  if (key[0] == '*')
    {
      my_delete_list(sh->env);
      sh->env = NULL;
      return (0);
    }
  tmp = *env;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->key, key) == 0)
	{
	  my_remove_in_list(tmp, sh);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (0);
}

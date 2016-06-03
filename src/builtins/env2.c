/*
** env2.c for  in /home/bedel_a/Projet/PSU/42sh/src/builtins
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Mon May 30 17:33:49 2016
** Last update Fri Jun  3 15:18:03 2016 Jean Jonathan
*/

#include "sh.h"

int             is_in_env(t_list *env, char *str)
{
  t_list        *tmp;

  tmp = env;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->key, str) == 0)
	{
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

char            *my_getenv(t_list *env, char *str)
{
  t_list        *tmp;

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

int             my_setenv(t_list **env, char *key, char *val)
{
  t_list        *tmp;

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

int             my_unsetenv(t_list **env, char *key, t_sh *sh)
{
  t_list        *tmp;

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

t_list  *cpy_env(t_list *env, char **e)
{
  int   i;
  char  **word;

  if (e[0] == NULL)
    my_setenv(&env, "PWD", getcwd(0, 0));
  i = 0;
  while (e[i] != NULL)
    {
      word = my_cut_in_tab(e[i], '=');
      if (word == NULL)
	return (NULL);
      my_put_in_list(&env, word[0], word[1]);
      freetab(word);
      i++;
    }
  return (env);
}

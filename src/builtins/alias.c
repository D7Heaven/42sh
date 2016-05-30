/*
** alias.c for  in /home/bedel_a/Projet/PSU/42sh/src/builtins
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Mon May 30 17:30:00 2016
** Last update Mon May 30 17:46:59 2016 
*/

#include "sh.h"

int     builtins_alias(t_sh *sh)
{
  print_list(sh->alias);
  return (0);
}

int     builtins_setalias(t_sh *sh)
{
  if (sh->av[1] != NULL && sh->av[2] != NULL)
    my_setalias(&sh->alias, sh->av);
  else
    my_printf("setalias [alias] [command]\n");
  return (0);
}

int     builtins_unsetalias(t_sh *sh)
{
  if (sh->av[1] != NULL)
    my_unsetalias(sh);
  else
    my_printf("unsetalias [key]\n");
  return (0);
}

char            *my_getalias(t_list *ali, char *str)
{
  t_list        *tmp;

  tmp = ali;
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

void            my_setalias2(t_list **ali, char *val, char **av)
{
  t_list        *tmp;

  tmp = *ali;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->key, av[1]) == 0)
	{
	  free(tmp->val);
	  tmp->val = my_strdup(val);
	  return;
	}
      tmp = tmp->next;
    }
  my_put_in_list(ali, av[1], val);
}

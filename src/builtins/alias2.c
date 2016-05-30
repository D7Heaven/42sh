/*
** alias2.c for  in /home/bedel_a/Projet/PSU/42sh/src/builtins
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Mon May 30 17:43:05 2016
** Last update Mon May 30 17:43:26 2016 
*/

#include "sh.h"

void            my_setalias(t_list **ali, char **av)
{
  char          *val;
  int           i;
  int           size;

  size = 0;
  i = 1;
  while (av[i] != NULL)
    size += my_strlen(av[i++]) + 1;
  i = 2;
  val = malloc(sizeof(char) * size + 1);
  my_memset(val, 0, size + 1);
  my_strcpy(val, av[i++]);
  while (av[i] != NULL)
    {
      my_strcat(val, " ");
      my_strcat(val, av[i++]);
    }
  my_setalias2(ali, val, av);
}

int             my_unsetalias(t_sh *sh)
{
  t_list        *tmp;

  tmp = sh->alias;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->key, sh->av[1]) == 0)
	{
	  my_remove_in_list(tmp, sh);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (0);
}

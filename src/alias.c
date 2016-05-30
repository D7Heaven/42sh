/*
** helper.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_my_select
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Thu Dec  3 16:15:13 2015 JEAN Jonathan
** Last update Tue Apr 12 15:25:30 2016 Jean Jonathan
*/

#include "sh.h"
#include "my.h"

char		*my_getalias(t_list *ali, char *str)
{
  t_list	*tmp;

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

void		my_setalias2(t_list **ali, char *val, char **av)
{
  t_list	*tmp;

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

void		my_setalias(t_list **ali, char **av)
{
  char		*val;
  int		i;
  int		size;

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

int		my_unsetalias(t_sh *sh)
{
  t_list	*tmp;

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

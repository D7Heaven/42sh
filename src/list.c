/*
** list.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_my_select
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Wed Dec  2 17:59:16 2015 JEAN Jonathan
** Last update Fri Jun  3 17:16:34 2016 tonell_m
*/

#include "sh.h"
#include "my.h"

int	     my_put_in_list(t_list **list, char *key, char *val)
{
  t_list      *elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (-1);
  elem->key = my_strdup(key);
  if (val == NULL)
    elem->val = NULL;
  else
    elem->val = my_strdup(val);
  elem->next = *list;
  elem->prev = NULL;
  if (*list != NULL)
    list[0]->prev = elem;
  *list = elem;
  return (0);
}

void		print_list(t_list *env)
{
  t_list	*tmp;

  tmp = env;
  while (tmp != NULL)
    {
      my_printf("%s=%s\n", tmp->key, tmp->val);
      tmp = tmp->next;
    }
}

int	free_elem(t_list *elem)
{
  if (elem)
    {
      if (elem->val)
	free(elem->val);
      if (elem->key)
	free(elem->key);
      free(elem);
    }
  return (0);
}

int	my_remove_in_list(t_list **list, t_sh *sh)
{
  if ((*list)->prev == NULL && (*list)->next == NULL)
    {
      sh->alias = NULL;
      return (0);
    }
  if ((*list)->prev == NULL)
    {
      *list = (*list)->next;
      (*list)->prev = NULL;
      return (0);
    }
  else
    (*list)->prev->next = (*list)->next;
  if ((*list)->next == NULL)
    (*list)->prev->next = NULL;
  else
    (*list)->next->prev = (*list)->prev;
  return (0);
}

int    my_delete_list(t_list *list)
{
  if (list == NULL)
    return (0);
  if (list->next == NULL)
    {
      free_elem(list);
      return (1);
    }
  list = list->next;
  while (list->next != NULL && list != NULL)
    {
      list = list->next;
      free_elem(list->prev);
    }
  return (1);
}

/*
** list.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_my_select
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Wed Dec  2 17:59:16 2015 JEAN Jonathan
** Last update Tue Apr 12 15:27:20 2016 Jean Jonathan
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

int	my_remove_in_list(t_list *list, t_sh *sh)
{
  if (list->prev == NULL && list->next == NULL)
    {
      free(list->val);
      free(list->key);
      free(list);
      sh->alias = NULL;
      return (0);
    }
  if (list->prev == NULL)
    list->next->prev = NULL;
  else
    list->prev->next = list->next;
  if (list->next == NULL)
    list->prev->next = NULL;
  else
    list->next->prev = list->prev;
  free(list->val);
  free(list->key);
  free(list);
  return (0);
}

int    my_delete_list(t_list *list)
{
  if (list == NULL)
    return (0);
  if (list->next == NULL)
    {
      free(list->val);
      free(list->key);
      free(list);
      return (1);
    }
  list = list->next;
  while (list->next != NULL && list != NULL)
    {
      free(list->prev->key);
      free(list->prev->val);
      free(list->prev);
      list = list->next;
    }
  if (list != NULL)
  {
    free(list->key);
    free(list->val);
    free(list);
  }
  return (1);
}

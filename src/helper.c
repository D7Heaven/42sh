/*
** helper.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell1
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Wed Jan  6 17:09:03 2016 JEAN Jonathan
** Last update Fri Jun  3 16:22:09 2016 tonell_m
*/

#include "sh.h"
#include "my.h"

char		*getcurpath()
{
  DIR		*cur;
  struct dirent	*dir;

  cur = opendir(".");
  dir = readdir(cur);
  closedir(cur);
  return (dir->d_name);
}

char		**envtotab(t_list *env)
{
  char		**tab;
  t_list	*tmp;
  int		i;

  tmp = env;
  i = 0;
  while (tmp != NULL && ++i)
    tmp = tmp->next;
  tmp = env;
  tab = malloc(sizeof(char *) * (i + 1));
  tab[i] = NULL;
  while (--i >= 0)
    {
      if (tmp->val == NULL)
	tmp->val = my_strdup("");
      tab[i] = malloc(sizeof(char) * (my_strlen(tmp->val)
				      + my_strlen(tmp->key) + 2));
      my_memset(tab[i], 0, my_strlen(tmp->val) + my_strlen(tmp->key) + 2);
      my_strcpy(tab[i], tmp->key);
      my_strcat(tab[i], "=");
      my_strcat(tab[i], tmp->val);
      tmp = tmp->next;
    }
  return (tab);
}

char	*epur_str(char *str)
{
  char	*tmp;
  int	i;
  int	k;

  i = 0;
  k = 0;
  tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 1));
  while ((str[i] == ' ') || (str[i] == '\t'))
    i++;
  while (str[i] != '\0')
  {
    tmp[k++] = str[i++];
    while ((str[i] == ' ') || (str[i] == '\t'))
      i++;
    if (((str[i - 1] == ' ') || (str[i - 1] == '\t')) && (str[i] != '\0'))
    {
      tmp[k] = ' ';
      k++;
    }
  }
  tmp[k] = '\0';
  free(str);
  return (tmp);
}

int	freetab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  return (0);
}

int	my_ngetnbr(char *str)
{
  int	i;
  int	output;
  int	neg;

  if (str == NULL)
    return (0);
  i = 0;
  output = 0;
  neg = is_neg(str);
  while (str[i] == '-' || str[i] == '+')
    i++;
  while (is_base(str[i]) == 1)
  {
    output = (output * 10) + (str[i] - 48);
    i++;
  }
  if (neg == 0)
    return (output);
  else
    return (-output);
}

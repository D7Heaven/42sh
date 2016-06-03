/*
** tree.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell2/src
**
** Made by Jean Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Tue Apr 12 14:34:45 2016 Jean Jonathan
** Last update Mon May 30 14:41:20 2016 Remi
*/

#include "my.h"
#include "sh.h"

int		find_op(t_tree *tree, char *str, int end, char **ops)
{
  int		i;
  int		j;
  char		inhib;

  j = 0;
  while (j < MAX_OPS)
    {
      i = end - 1;
      inhib = 0;
      while (i >= 0)
        {
	  if (*(str + i) == '\"')
	    inhib++;
          if ((my_strncmp(str + i, ops[j], my_strlen(ops[j])) == 0) &&
	      inhib % 2 == 0)
            {
              if ((tree->str = malloc(sizeof(char)
                                      * my_strlen(ops[j] + 1))) == NULL)
                return (-2);
              tree->str = my_strdup(ops[j]);
              return (i + my_strlen(ops[j]));
            }
          i--;
        }
      j++;
    }
  return (-1);
}

void		free_tree(t_tree *tree)
{
  if (tree->left != NULL && tree->right != NULL)
    {
      free_tree(tree->left);
      free_tree(tree->right);
    }
  free(tree);
}

void		check_redirect(t_tree *tree)
{
  char		**tmp;
  int		i;

  if ((my_strcmp(tree->str, ">") == 0 || my_strcmp(tree->str, ">>") == 0)
      && tree->left->str[0] == 0)
    {
      tmp = my_cut_in_tab(tree->right->str, ' ');
      i = 0;
      while (tree->right->str[i] && tree->right->str[i] != ' ')
        i++;
      tree->left->str = my_strdup(&tree->right->str[i + 1]);
      tree->right->str = my_strdup(tmp[0]);
      freetab(tmp);
    }
  if (tree->left != NULL && tree->right != NULL)
    {
      check_redirect(tree->left);
      check_redirect(tree->right);
    }
}

int		get_op_lenght(char *str, char **ops)
{
  int		i;

  i = 0;
  while (i < MAX_OPS)
    {
      if (my_strncmp(str, ops[i], my_strlen(ops[i])) == 0)
        return (my_strlen(ops[i]));
      i++;
    }
  return (-1);
}

t_tree		*create_tree(t_tree *parent, char *str, char **ops, int end)
{
  t_tree	*tree;
  int		i;

  if ((tree = malloc(sizeof(t_tree))) == NULL)
    return (NULL);
  if ((i = find_op(tree, str, end, ops)) == -1)
    tree->str = my_strdup(str);
  tree->parent = parent;
  init_tree(tree);
  tree->str = epur_str(tree->str);
  my_memset(str + i - get_op_lenght(tree->str, ops), 0,
            get_op_lenght(tree->str, ops));
  if (i != -1) {
    tree->left = create_tree(tree, str, ops,
                             i - get_op_lenght(tree->str, ops));
    tree->right = create_tree(tree, str + i, ops, my_strlen(str + i));
  }
  else
    finish_tree(tree);
  return (tree);
}

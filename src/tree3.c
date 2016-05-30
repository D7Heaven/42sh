/*
** tree3.c for enza in /home/arnoulr/rendu/PSU/42sh
**
** Made by Remi
** Login   <arnoulr@epitech.net>
**
** Started on  Mon May 30 14:39:42 2016 Remi
** Last update Mon May 30 14:41:07 2016 Remi
*/

#include "sh.h"

void		finish_tree(t_tree *tree)
{
  tree->left = NULL;
  tree->right = NULL;
}

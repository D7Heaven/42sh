/*
** pipe.c for ebvjz in /home/arnoulr/rendu/PSU/42sh
**
** Made by Remi
** Login   <arnoulr@epitech.net>
**
** Started on  Mon May 30 13:26:20 2016 Remi
** Last update Tue May 31 16:19:23 2016 Remi
*/

#include "sh.h"

char            *my_strdup_pure(char *str)
{
  char          *s;
  int           i;

  i = 0;
  while ((str[i] == ' ' || str[i] == '\v'
	  || str[i] == '\t' || str[i] == '\n') && str[i] != '\0')
    i++;
  if (i == my_strlen(str))
    return (NULL);
  s = my_strdup(&str[i]);
  i = my_strlen(s) - 1;
  while ((s[i] == ' ' || s[i] == '\n' || str[i] == '\v'
	  || str[i] == '\t') && i >= 0)
    i--;
  s[i + 1] = '\0';
  return (s);
}

void            create_pipe(t_tree *ast)
{
  t_tree	*tmp;
  t_tree	*cmd_tmp;

  tmp = ast->right;
  cmd_tmp = ast->left;
  while (my_strcmp(tmp->str, "|") == 0 || my_strcmp(tmp->str, ">") == 0 ||
	 my_strcmp(tmp->str, ">>") == 0 || my_strcmp(tmp->str, "<") == 0 ||
	 my_strcmp(tmp->str, "<<") == 0)
    tmp = tmp->left;
  while (my_strcmp(cmd_tmp->str, "|") == 0 ||
	 my_strcmp(cmd_tmp->str, ">") == 0 ||
	 my_strcmp(cmd_tmp->str, ">>") == 0 ||
	 my_strcmp(cmd_tmp->str, "<") == 0 ||
	 my_strcmp(cmd_tmp->str, "<<") == 0)
    {
      if (my_strcmp(cmd_tmp->str, "<") == 0)
	cmd_tmp = cmd_tmp->left;
      else
	cmd_tmp = cmd_tmp->right;
    }
  pipe(ast->pipe);
  cmd_tmp->piper_write = ast;
  tmp->piper_read = ast;
  cmd_tmp->fd[1] = ast->pipe[1];
  tmp->fd[0] = ast->pipe[0];
}

void            create_new2(t_tree **tmp, t_tree **cmd_tmp, char *new, int i)
{
  while (my_strcmp(cmd_tmp[0]->str, "|") == 0
	 || my_strcmp(cmd_tmp[0]->str, ">") == 0 ||
	 my_strcmp(cmd_tmp[0]->str, ">>") == 0
	 || my_strcmp(cmd_tmp[0]->str, "<") == 0 ||
	 my_strcmp(cmd_tmp[0]->str, "<<") == 0)
    {
      if (my_strcmp(cmd_tmp[0]->str, "<") == 0)
	cmd_tmp[0] = cmd_tmp[0]->left;
      else
	cmd_tmp[0] = cmd_tmp[0]->right;
    }
  if (my_strcmp(tmp[0]->str, "|") == 0 || my_strcmp(tmp[0]->str, ">") == 0 ||
	 my_strcmp(tmp[0]->str, ">>") == 0 ||
	 my_strcmp(tmp[0]->str, "<") == 0 ||
	 my_strcmp(tmp[0]->str, "<<") == 0
      || my_strcmp(cmd_tmp[0]->str, tmp[0]->str) == 0)
    {

      while (tmp[0]->str[i] != ' ' && tmp[0]->str[i] != '\0')
	i++;
      cmd_tmp[0]->str = my_strdup_pure(&tmp[0]->str[i]);
      new = my_strdup_pure(tmp[0]->str);
      new[i] = '\0';
      tmp[0]->str = new;
    }
}

void            create_new_file(t_tree *ast)
{
  t_tree	*tmp;
  t_tree	*cmd_tmp;
  char          *new;
  int           i;

  i = 0;
  tmp = ast->right;
  cmd_tmp = ast->left;
  while (my_strcmp(tmp->str, "|") == 0 || my_strcmp(tmp->str, ">") == 0 ||
	 my_strcmp(tmp->str, ">>") == 0 || my_strcmp(tmp->str, "<") == 0 ||
	 my_strcmp(tmp->str, "<<") == 0)
    tmp = tmp->left;
  new = NULL;
  create_new2(&tmp, &cmd_tmp, new, i);
  if (my_strcmp(ast->str, ">") == 0)
    cmd_tmp->fd[1] = open((const char *)(tmp->str), O_RDWR
		       | O_CREAT | O_TRUNC, 0644);
  else
    cmd_tmp->fd[1] = open((const char *)(tmp->str), O_RDWR | O_CREAT
		       | O_APPEND, 0644);
}

void            open_new_file(t_tree *ast)
{
  t_tree	*tmp;
  t_tree	*cmd_tmp;
  int           i;
  char          *new;

  i = 0;
  tmp = ast->right;
  cmd_tmp = ast->left;
  open_new_file2(tmp, cmd_tmp);
  if (my_strcmp(tmp->str, "|") != 0 && my_strcmp(tmp->str, ">") != 0 &&
      my_strcmp(tmp->str, ">>") != 0 && my_strcmp(tmp->str, "<") != 0 &&
      my_strcmp(tmp->str, "<<") != 0)
    if (cmd_tmp->str[0] == '|' || cmd_tmp->str[0] == '>' ||
	cmd_tmp->str[0] == '<' || my_strcmp(cmd_tmp->str, tmp->str) == 0)
      {
	while (tmp->str[i] != ' ' && tmp->str[i] != '\0')
	  i++;
	cmd_tmp->str = my_strdup_pure(&tmp->str[i]);
	new = my_strdup_pure(tmp->str);
	new[i] = '\0';
	tmp->str = new;
      }
  if (tmp->str != NULL && my_strcmp(ast->str, "<") == 0)
    cmd_tmp->fd[0] = open((const char *)(tmp->str), O_RDONLY);
}

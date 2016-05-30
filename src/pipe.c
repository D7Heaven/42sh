/*
** pipe.c for ebvjz in /home/arnoulr/rendu/PSU/42sh
**
** Made by Remi
** Login   <arnoulr@epitech.net>
**
** Started on  Mon May 30 13:26:20 2016 Remi
** Last update Mon May 30 14:38:42 2016 Remi
*/

#include "sh.h"

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

/*
void            create_new2(t_ast **tmp, t_ast **cmd_tmp, char *new, int i)
{
  while (cmd_tmp[0]->operand != 0)
    {
      if (cmd_tmp[0]->operand == '<')
	cmd_tmp[0] = cmd_tmp[0]->left;
      else
	cmd_tmp[0] = cmd_tmp[0]->right;
    }

  if (cmd_tmp[0]->cmd == NULL || my_strcmp(cmd_tmp[0]->cmd, tmp[0]->cmd) == 0)
    {

      while (tmp[0]->cmd[i] != ' ' && tmp[0]->cmd[i] != '\0')
	i++;
      cmd_tmp[0]->cmd = my_strdup_pure(&tmp[0]->cmd[i]);
      new = my_strdup_pure(tmp[0]->cmd);
      new[i] = '\0';
      tmp[0]->cmd = new;
    }

}

void            create_new_file(t_ast *ast)
{
  t_ast         *tmp;
  t_ast         *cmd_tmp;
  char          *new;
  int           i;

  i = 0;
  tmp = ast->right;
  cmd_tmp = ast->left;
  while (tmp->operand != 0)
    tmp = tmp->left;
  tmp->done = 1;
  create_new2(&tmp, &cmd_tmp, new, i);
  if (tmp->cmd != NULL && ast->operand == '>')
    cmd_tmp->fd = open((const char *)(tmp->cmd), O_RDWR
		       | O_CREAT | O_TRUNC, 0644);
  else if (tmp->cmd != NULL)
    cmd_tmp->fd = open((const char *)(tmp->cmd), O_RDWR | O_CREAT
		       | O_APPEND, 0644);
}
*/

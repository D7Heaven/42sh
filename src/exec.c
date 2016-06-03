/*
** exec.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell2
**
** Made by Jean Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Tue Apr 12 15:15:13 2016 Jean Jonathan
** Last update Fri Jun  3 11:57:27 2016 Jean Jonathan
*/

#include "sh.h"
#include "my.h"

int     check_ops2(char *str, t_tree *tree)
{
  if (my_strcmp(str, ">") == 0)
    create_new_file(tree);
  else if (my_strcmp(str, ">>") == 0)
    create_new_file(tree);
  else if (my_strcmp(str, "<") == 0)
    open_new_file(tree);
  else
    return (1);
  if (tree->fd[1] < 0)
    {
      my_printf("Can't open %s\n", tree->right->str);
      tree->fd[1] = -1;
    }
  return (0);
}

int     check_ops(char *str, t_tree *tree)
{
  if (tree->parent != NULL)
    {
      if ((my_strcmp(tree->parent->str, ">") == 0
           || my_strcmp(tree->parent->str, ">>") == 0)
          && tree == tree->parent->right)
        return (0);
      if ((my_strcmp(tree->parent->str, "<") == 0)
          && tree == tree->parent->right)
        return (0);
    }
  if (my_strcmp(str, ";") == 0)
    return (0);
  else if (my_strcmp(str, "&&") == 0)
    return (0);
  else if (my_strcmp(str, "||") == 0)
    return (0);
  else if (my_strcmp(str, "|") == 0)
    {
      create_pipe(tree);
      return (0);
    }
  else
    return (check_ops2(str, tree));
}

void    dad(t_sh *sh, pid_t pid)
{
  int   status;
  char	buff[5];

  my_memset(buff, 0, 5);
  if (sh->actual->piper_read!= NULL && sh->actual->fd[0] != 0)
    {
      close(sh->actual->piper_read->pipe[0]);
      close(sh->actual->piper_read->pipe[1]);
    }
  waitpid(pid, &status, 0);
  if (WIFEXITED(status))
      return_exec_success(sh);
  sprintf(buff, "%d", WEXITSTATUS(status));
  my_setenv(&sh->env, "?", buff);
  if (WTERMSIG(status) == SIGSEGV)
    write(2, "Segmentation Fault\n", 19);
  freetab(sh->av);
}

int    son(t_sh *sh, char *path, char **e)
{
  if (sh->actual->fd[1] != 1)
    {
      if (sh->actual->piper_write != NULL)
	close(sh->actual->piper_write->pipe[0]);
      dup2(sh->actual->fd[1], 1);
      close(sh->actual->fd[1]);
    }
  if (sh->actual->fd[0] != 0)
    {
      if (sh->actual->piper_read != NULL)
	close(sh->actual->piper_read->pipe[1]);
      if (sh->actual->fd[0] == -1)
	exit(0);
      dup2(sh->actual->fd[0], 0);
      close(sh->actual->fd[0]);
    }
  e = envtotab(sh->env);
  if ((execve(path, sh->av, e)) == 0)
    my_delete_list(sh->env);
  else
    {
      my_setenv(&sh->env, "?", "1");
      return (my_printf("%s: Can't execute\n", sh->av[0]));
    }
  return (0);
}

int             my_exec(t_sh *sh, char *path)
{
  pid_t         pid;

  if (sh->actual->parent != NULL
      && (sh->actual->parent->fd[0] < 0 || sh->actual->parent->fd[1] < 0))
    return (0);
  pid = fork();
  if (pid == 0)
    son(sh, path, NULL);
  else if (pid > 0)
    dad(sh, pid);
  else
    my_printf("%s: Fork failed\n", sh->av[0]);
  return (0);
}

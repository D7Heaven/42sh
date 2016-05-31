/*
** main.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell2/src
**
** Made by Jean Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Tue Apr 12 14:29:16 2016 Jean Jonathan
** Last update Tue May 31 14:44:46 2016 Jean Jonathan
*/

#include "my.h"
#include "sh.h"

void    free_ops(char **ops)
{
  int   i;

  i = 0;
  while (i < MAX_OPS)
    {
      free(ops[i]);
      i++;
    }
  free(ops);
}

void	sig_handler(int signo)
{
  if (signo == SIGINT || signo == SIGQUIT)
    return;
}

int	my_init(t_sh *sh, char **e)
{
  sh->alias = NULL;
  sh->env = NULL;
  sh->env = cpy_env(sh->env, e);
  sh->ops = fill_ops();
  init_builtins(sh);
  if (signal(SIGINT, &sig_handler) == SIG_ERR)
    my_printf("Can't catch signal.\n");
  if (signal(SIGQUIT, &sig_handler) == SIG_ERR)
    my_printf("Can't catch signal.\n");
  load_rc(sh);
  return (0);
}

void    treat(t_sh *sh, char *buff)
{
  char  **t;
  int   i;

  if (buff[my_strlen(buff) - 1] == '\n')
    buff[my_strlen(buff) - 1] = 0;
  if (buff[0] == 0)
    return;
  t = my_cut_in_tab(buff, '\n');
  i = 0;
  while (t[i] != NULL)
    {
      sh->tree = create_tree(NULL, t[i], sh->ops, my_strlen(t[i]));
      add_history(sh, t[i]);
      sh->error = 0;
      check_redirect(sh->tree);
      error_tree(sh->tree, sh);
      if (sh->error == 1)
        my_printf("Parse error\n");
      else
        exec_tree(sh->tree, sh);
      free_tree(sh->tree);
      i++;
    }
  freetab(t);
}

int	main(int ac, char *av[], char *e[])
{
  char	buff[BUFF_SIZE];
  t_sh	sh;

  (void)ac;
  (void)av;
  my_init(&sh, e);
  my_memset(buff, 0, BUFF_SIZE);
  while (my_strncmp(buff, "exit", 4) != 0)
    {
      my_memset(buff, 0, BUFF_SIZE);
      print_prompt(&sh);
      if (read(0, buff, BUFF_SIZE) > 0)
        treat(&sh, buff);
      else
        builtins_exit(&sh, 1);
    }
  return (0);
}

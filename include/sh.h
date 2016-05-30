/*
** sh.h for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell2
**
** Made by Jean Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Tue Apr 12 15:21:34 2016 Jean Jonathan
** Last update Tue Apr 12 15:24:54 2016 Jean Jonathan
*/

#ifndef PSU_2015_MINISHELL2_SH_H
#define PSU_2015_MINISHELL2_SH_H

#include <wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>

#define	BUFF_SIZE       (4096)
#define MAX_OPS         (5)

typedef struct s_list {
  char		*key;
  char		*val;
  struct s_list *next;
  struct s_list *prev;
} t_list;

typedef struct s_tree
{
  char          *str;
  int           fd[2];
  int           pipe;
  struct s_tree *parent;
  struct s_tree *left;
  struct s_tree *right;
} t_tree;

typedef struct s_sh {
  t_list        *env;
  char          **av;
  char          **ops;
  int           error;
  t_tree         *tree;
  t_tree        *actual;
  t_list	*alias;
} t_sh;

void    error_tree(t_tree *, t_sh *);
void    check_redirect(t_tree *);
void    my_exit(t_sh *, int);
void    free_ops(char **);
void    treat(t_sh *, char *);
int     is_base(char);
int     is_neg(char *);
void    free_tree(t_tree *);
char    **fill_ops();
int     my_ngetnbr(char *);
int     my_exec(t_sh *, char *);
int     check_commands(t_sh *, int, char *, char **);
int     check_builtins(t_sh *, char *, t_tree *);
int     check_builtins2(t_sh *);
char    *getcurpath();
int     freetab(char **);
void    exec_tree(t_tree *, t_sh *);
void    print_prompt(t_sh *);
int     my_cd(t_list **, char *);
int     my_put_in_list(t_list **, char *, char *);
int     my_delete_list(t_list *);
int     my_remove_in_list(t_list *, t_sh *);
char    *my_getenv(t_list *, char *);
int     my_setenv(t_list **, char *, char *);
int     my_unsetenv(t_list **, char *, t_sh *);
char    *my_getalias(t_list *, char *);
void    my_setalias(t_list **, char **);
int     my_unsetalias(t_sh *);
void    print_list(t_list *);
t_list  *cpy_env(t_list *, char **);
int     check_alias(t_sh *, t_list *, int, int);
char    **envtotab(t_list *);
int     load_rc(t_sh *);
char    *epur_str(char *);
int     check_ops(char *, t_tree *);
t_tree  *create_tree(t_tree *, char *, char **, int);
#endif /* PSU_2015_MINISHELL2_SH_H */

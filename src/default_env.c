/*
** default_env.c for  in /home/bedel_a/Projet/PSU/42sh
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Wed Jun  1 16:38:17 2016
** Last update Wed Jun  1 16:43:28 2016 
*/

#include <grp.h>
#include <pwd.h>
#include "sh.h"

void		check_env(t_sh *sh)
{
  char		hostname[1024];
  struct group	*grp;
  struct passwd *pw;
  uid_t		uid;
  char		*cwd;
  struct passwd *pww;
  char *homedir;

  pww = getpwuid(getuid());
  homedir  = pww->pw_dir;
  cwd = getcwd (0, 0);
  uid = geteuid ();
  pw = getpwuid (uid);
  my_memset(hostname, 0, 1024);
  gethostname(hostname, 1023);
  grp = getgrgid(getgid());
  my_setenv(&sh->env, "HOME", homedir);
  my_setenv(&sh->env, "HOST", hostname);
  my_setenv(&sh->env, "GROUP", grp->gr_name);
  my_setenv(&sh->env, "USER", pw->pw_name);
  my_setenv(&sh->env, "LOGNAME", pw->pw_name);
  my_setenv(&sh->env, "PWD", cwd);
}

/*
** message.c for  in /home/jeanj/Rendu/PSU_2015/42sh
**
** Made by Jean Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Fri Jun  3 15:42:17 2016 Jean Jonathan
** Last update Tue Jun  7 13:37:53 2016 Jean Jonathan
*/

#include "sh.h"

void		handle_message(int status)
{
  if (WTERMSIG(status) == SIGSEGV)
    {
      write(2, "Segmentation fault", 18);
      if (WCOREDUMP(status))
        write(2, "(core dumped)", 13);
      write(2, "\n", 1);
      exit(139);
    }
  else if (WTERMSIG(status) == SIGFPE)
    {
      write(2, "Floating exception", 18);
      if (WCOREDUMP(status))
        write(2, "(core dumped)", 13);
      write(2, "\n", 1);
      exit(136);
    }
  else if (WTERMSIG(status) == SIGPIPE)
    write(2, "Broken pipe\n", 12);
  else if (WTERMSIG(status) == SIGKILL)
    write(2, "Killed\n", 7);
  else if (WTERMSIG(status) == SIGQUIT)
    write(2, "Quit (core dumped)\n", 19);
  else if (WTERMSIG(status) == SIGABRT)
    write(2, "Abort (core dumped)\n", 20);
}

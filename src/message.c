/*
** message.c for  in /home/jeanj/Rendu/PSU_2015/42sh
**
** Made by Jean Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Fri Jun  3 15:42:17 2016 Jean Jonathan
** Last update Fri Jun  3 18:17:17 2016 Jean Jonathan
*/

#include "sh.h"

void		handle_message(int status)
{
  if (WTERMSIG(status) == SIGSEGV)
    {
      write(2, "Segmentation fault\n", 33);
      exit(139);
    }
  else if (WTERMSIG(status) == SIGFPE)
    {
      write(2, "Floating exception\n", 33);
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
  else if (WTERMSIG(status) == SIGBUS)
    write(2, "Bus error (core dumped)\n", 24);
}

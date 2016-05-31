/*
** file.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell1
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Fri Jan  8 18:34:45 2016 JEAN Jonathan
** Last update Tue May 31 15:08:39 2016 Jean Jonathan
*/

#include "sh.h"

int	load_rc(t_sh *sh)
{
  int	fd;
  char	*str;
  char	*home;
  char	*read;

  read = NULL;
  if ((home = my_getenv(sh->env, "HOME")) == NULL)
    return (my_printf("Can't locate HOME variable\n"));
  str = malloc(sizeof(char) * (my_strlen(home) + 7));
  my_memset(str, 0, my_strlen(home) + 7);
  my_strcpy(str, home);
  my_strcat(str, "/.42rc");
  fd = open(str, O_RDONLY);
  free(str);
  if (fd == -1)
    return (1);
  while ((read = get_next_line(fd)) != NULL)
    {
      if (read[0] != '#' && read[0] != '\0')
	    treat(sh, read);
      free(read);
    }
  close(fd);
  return (0);
}

int     add_history(t_sh *sh, char *add)
{
  int	fd;
  char	*home;
  char  *str;

  if ((home = my_getenv(sh->env, "HOME")) == NULL)
    return (my_printf("Can't locate HOME variable\n"));
  str = malloc(sizeof(char) * (my_strlen(home) + 12));
  my_memset(str, 0, my_strlen(home) + 12);
  my_strcpy(str, home);
  my_strcat(str, "/.42history");
  fd = open(str, O_CREAT | O_APPEND | O_RDWR, 0666);
  free(str);
  if (fd == -1)
    return (1);
  write(fd, add, strlen(add));
  write(fd, "\n", 1);
  close(fd);
  return (0);
}

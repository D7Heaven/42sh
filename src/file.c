/*
** file.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell1
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Fri Jan  8 18:34:45 2016 JEAN Jonathan
** Last update Sun Jan 24 11:43:17 2016 JEAN Jonathan
*/

#include "sh.h"
#include "my.h"

int	load_rc(t_sh *sh)
{
  int	fd;
  char	*str;
  char	*home;
  char	*read;

  read = NULL;
  if ((home = my_getenv(sh->env, "HOME")) == NULL)
    return (my_printf("Can't locate HOME variable\n"));
  str = malloc(sizeof(char) * (my_strlen(home) + 9));
  my_memset(str, 0, my_strlen(home) + 9);
  my_strcpy(str, home);
  my_strcat(str, "/.myshrc");
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

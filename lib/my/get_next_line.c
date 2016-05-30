/*
** get_next_line.c for  in /home/jeanj/Rendu/CPE_2015/CPE_2015_getnextline
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Fri Jan 15 13:14:31 2016 JEAN Jonathan
** Last update Wed Jan 20 10:02:29 2016 JEAN Jonathan
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*norme(int *i, int *j, char *str, int type)
{
  if (type == 0)
    {
      *(i)++;
      *j = 0;
    }
  else
    *i = -1;
  return (str);
}

char	*my_malloc(int nb)
{
  char	*new;
  int	i;

  i = 0;
  if ((new = malloc(sizeof(char) * nb + 1)) == NULL)
    return (NULL);
  i = 0;
  while (i < nb + 1)
    new[i++] = 0;
  return (new);
}

char	*remalloc(char *str)
{
  char	*new;
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i] != '\0')
    i++;
  if ((new = malloc(sizeof(char) * (i + READ_SIZE + 1))) == NULL)
    return (NULL);
  while (j < i + READ_SIZE + 1)
    new[j++] = 0;
  j = 0;
  while (str[j])
    new[j] = str[j++];
  free(str);
  return (new);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE];
  static char	*str;
  static int	i = 0;
  static int	j = 0;
  static int	nb;

  if (i == -1)
    return (NULL);
  if (i == 0)
    {
      if ((nb = read(fd, buff, READ_SIZE)) == 0)
	return (norme(&i, &j, str, 1));
    }
  if (j == 0)
    str = my_malloc(READ_SIZE + 1);
  else
    str = remalloc(str);
  while (i < nb)
    {
      if (buff[i] == '\n' || buff[i] == '\0')
	return (norme(&i, &j, str, 0));
      str[j++] = buff[i++];
    }
  i = 0;
  get_next_line(fd);
}

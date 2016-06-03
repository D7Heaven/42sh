/*
** get_next_line.c for gnl in /home/tonell_m/rendu/CPE/CPE_2015_getnextline
**
** Made by Marceau TONELLI
** Login   <tonell_m@epitech.net>
**
** Started on  Mon Jan  4 15:26:26 2016 Marceau TONELLI
** Last update Wed Jan  6 17:19:24 2016 Marceau TONELLI
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int			my_strlen(char *str)
{
  int			j;

  j = 0;
  while (str[j] != 0)
    j++;
  return (j);
}

char			*my_strncat(char *src, char *str, int *i)
{
  char			*res;
  int			k;

  if ((res = malloc(sizeof(char) * (my_strlen(src) + READ_SIZE + 1))) == NULL)
    return (NULL);
  k = -1;
  while (src[++k] != 0)
    res[k] = src[k];
  while (str[*i] != 0 && str[*i] != '\n')
    res[k++] = str[(*i)++];
  res[k] = 0;
  free(src);
  return (res);
}

int			is_line(char *str, char b, int *i)
{
  int			j;

  j = *i;
  if (b == 0)
    j = 0;
  while (str[j] != 0)
    {
      if (str[j] == '\n')
	return (1);
      j++;
    }
  return (0);
}

char			*normandie(const int fd, char *str, char *buf, int *i)
{
  int			n;

  while ((n = read(fd, buf, READ_SIZE)) > 0)
    {
      *i = 0;
      if (n == -1)
	return (NULL);
      buf[n] = 0;
      str = my_strncat(str, buf, i);
      if (is_line(buf, 0, i) == 1)
	{
	  (*i)++;
	  return (str);
	}
    }
  if (str[0] != 0)
    return (str);
  free(str);
  return (NULL);
}

char			*get_next_line(const int fd)
{
  static char		buf[READ_SIZE + 1];
  static int		i = 0;
  char			*str;

  if ((str = malloc(sizeof(char))) == NULL)
    return (NULL);
  str[0] = 0;
  if (buf[i] == '\n')
    {
      i++;
      return (str);
    }
  str = my_strncat(str, buf, &i);
  if (is_line(buf, 1, &i) == 1)
    {
      i++;
      return (str);
    }
  if ((str = normandie(fd, str, buf, &i)) != NULL)
    return (str);
  free(str);
  return (NULL);
}

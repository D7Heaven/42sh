/*
** my_strcmp.c for my_strcmp in /home/jean_j/rendu/Piscine_C_J06/ex_06
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Mon Oct  5 12:49:46 2015 jean jonathan
** Last update Wed Nov 25 13:22:43 2015 JEAN Jonathan
*/

#include <stdlib.h>
#include "my.h"

int	my_casecmp(char *str1, char *str2)
{
  int   i;
  char  *s1;
  char  *s2;
  int   res;

  s1 = lower_str(str1);
  s2 = lower_str(str2);
  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    i++;
  res = s1[i] - s2[i];
  if (s1[i] == '\0' && s2[i] == '\0')
    res = 0;
  else if (s1[i] == '\0')
    res = -1;
  else if (s2[i] == '\0')
    res = 1;
  free(s1);
  free(s2);
  return (res);
}

char	*lower_str(char *s)
{
  int           i;
  char          *str;

  i = 0;
  str = strdup(s);
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + 32;
      i++;
    }
  return (str);
}

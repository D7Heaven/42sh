/*
** my_strdup.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_my_select/lib/my
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Fri Dec  4 13:17:09 2015 JEAN Jonathan
** Last update Tue Dec  8 18:16:40 2015 JEAN Jonathan
*/

#include <stdlib.h>

char	*my_memset(char *str, char c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    str[i++] = c;
  return (str);
}

char            *my_strdup(char *src)
{
  char          *dest;
  int           i;

  dest = malloc(my_strlen(src) + 1);
  dest = my_memset(dest, '\0', my_strlen(src) + 1);
  if (dest == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    dest[i] = src[i++];
  return (dest);
}

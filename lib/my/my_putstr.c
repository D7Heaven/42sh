/*
** my_putstr.c for my_putstr in /home/jean_j/day04
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Thu Oct  1 10:13:50 2015 jean jonathan
** Last update Mon Nov 23 17:57:46 2015 JEAN Jonathan
*/

#include <stdlib.h>
#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (my_putstr("(null)"));
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (i);
}

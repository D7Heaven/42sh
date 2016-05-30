/*
** my_getnbr.c for getnbr in /home/jean_j/rendu/Piscine_C_J10/lib/my
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Sat Oct 10 09:01:21 2015 jean jonathan
** Last update Sun Jan 24 15:05:20 2016 JEAN Jonathan
*/

#include <stdlib.h>
#include "my.h"

int	is_neg(char *str)
{
  int	count;
  int	i;

  i = 0;
  count = 0;
  while (str[i] < '0' || str[i] > '9')
    {
      if (str[i] == '-')
	count++;
      i++;
    }
  if (count % 2 != 0)
    return (1);
  else
    return (0);
}

int	is_base(char a)
{
  if (a >= '0' && a <= '9')
    {
      return (1);
    }
  else
    {
      return (0);
    }
}

int	my_getnbr(char *str)
{
  int	i;
  int	output;
  int	neg;

  if (str == NULL)
    return (0);
  i = 0;
  output = 0;
  neg = 0;
  while (str[i] == '-' || str[i] == '+')
    i++;
  while (is_base(str[i]) == 1)
    {
      output = (output * 10) + (str[i] - 48);
      i++;
    }
  return (output);
}

/*
** my_put_nbr.c for my_put_nbr in /home/jean_j/day03
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Wed Sep 30 14:00:41 2015 jean jonathan
** Last update Mon Nov 23 17:58:05 2015 JEAN Jonathan
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int	mod;
  int	i;

  i = 0;
  if (nb < 0 && nb != -2147483648)
    {
      i += my_putchar('-');
      nb = -nb;
    }
  if (nb >= 10 && nb != -2147483648)
    {
      mod = (nb) % 10;
      nb = (nb - mod) / 10;
      i += my_put_nbr(nb);
      i += my_putchar('0' + mod);
    }
  else if (nb == -2147483648)
    {
      i += my_putchar('-');
      i += my_putchar('2');
      i += my_put_nbr(147483648);
    }
  else
    i += my_putchar('0' + nb);
  return (i);
}

int	my_put_nbr_unsigned(unsigned int nb)
{
  unsigned int	mod;
  int		i;

  i = 0;
  if (nb >= 10)
    {
      mod = (nb) % 10;
      nb = (nb - mod) / 10;
      i += my_put_nbr_unsigned(nb);
      i += my_putchar('0' + mod);
    }
  else
    i += my_putchar('0' + nb);
  return (i);
}

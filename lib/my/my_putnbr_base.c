/*
** my_put_nbr_base.c for  in /home/jean_j/rendu/PSU_2015/PSU_2015_my_printf
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Wed Nov  4 13:48:36 2015 jean jonathan
** Last update Fri Jan 22 12:56:38 2016 JEAN Jonathan
*/

#include "my.h"

int     my_putnbr_base(int nbr, char *base)
{
  int	i;
  int	size;
  int	nb;

  i = 0;
  if (nbr < 0)
    {
      nbr = - nbr;
      i += my_putchar('-');
    }
  size = my_strlen(base);
  if (nbr > 0)
    {
      nb = nbr;
      nbr /= size;
      i += my_putnbr_base(nbr, base);
      i += my_putchar(base[nb % size]);
    }
  return (i);
}

int     my_putnbr_base_u(unsigned int nbr, char *base)
{
  int		i;
  int		size;
  unsigned int	nb;

  i = 0;
  if (nbr < 0)
    {
      nbr = - nbr;
      i += my_putchar('-');
    }
  size = my_strlen(base);
  if (nbr > 0)
    {
      nb = nbr;
      nbr /= size;
      i += my_putnbr_base_u(nbr, base);
      i += my_putchar(base[nb % size]);
    }
  return (i);
}

int     my_putnbr_base_long(long nbr, char *base)
{
  int	i;
  int	size;
  long	nb;

  i = 0;
  if (nbr < 0)
    {
      nbr = - nbr;
      i += my_putchar('-');
    }
  size = my_strlen(base);
  if (nbr > 0)
    {
      nb = nbr;
      nbr /= size;
      i += my_putnbr_base_long(nbr, base);
      i += my_putchar(base[nb % size]);
    }
  return (i);
}

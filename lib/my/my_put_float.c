/*
** my_put_float.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_my_printf
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Fri Nov 13 14:28:35 2015 JEAN Jonathan
** Last update Mon Nov 23 17:56:42 2015 JEAN Jonathan
*/

#include "my.h"

int             my_put_float(double nbr)
{
  long          dec;
  long          ent;
  double	aff_dec;
  int           i;

  i = 0;
  ent = nbr;
  dec = nbr * (float)1000000;
  dec -= ent * 1000000;
  aff_dec = (double)dec;
  i += my_putnbr_base_long(ent, "0123456789");
  i += my_putchar('.');
  i += my_putnbr_base_long((long)aff_dec, "0123456789");
  return (i);
}

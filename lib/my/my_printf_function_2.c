/*
** my_printf_function_2.c for  in /home/jean_j/rendu/PSU_2015/PSU_2015_my_printf
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Wed Nov  4 15:55:16 2015 jean jonathan
** Last update Mon Nov 23 17:55:59 2015 JEAN Jonathan
*/

#include <stdarg.h>
#include "my.h"

int	my_print_hexa_upper(va_list ag)
{
  return (my_putnbr_base_u(va_arg(ag, unsigned int), "0123456789ABCDEF"));
}

int	my_print_octal(va_list ag)
{
  return (my_putnbr_base_u(va_arg(ag, unsigned int), "01234567"));
}

int	my_print_bool(va_list ag)
{
  unsigned int	bool;

  bool = va_arg(ag, unsigned int);
  if (bool == 1)
    return (my_putstr("true"));
  else
    return (my_putstr("false"));
}

int	my_print_address(va_list ag)
{
  int	i;

  i = 0;
  i += my_putstr("0x");
  i += my_putnbr_base_long(va_arg(ag, long long), "0123456789abcdef");
  return (i);
}

int	my_print_unsigned(va_list ag)
{
  return (my_put_nbr_unsigned(va_arg(ag, unsigned int)));
}

/*
** my_printf_function_1.c for  in /home/jean_j/rendu/PSU_2015/PSU_2015_my_printf
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Wed Nov  4 10:57:55 2015 jean jonathan
** Last update Mon Nov 23 17:55:52 2015 JEAN Jonathan
*/

#include <stdarg.h>
#include "my.h"

int	my_print_char(va_list ag)
{
  return (my_putchar((char)va_arg(ag, int)));
}

int	my_print_str(va_list ag)
{
  return (my_putstr(va_arg(ag, char*)));
}

int	my_print_int(va_list ag)
{
  return (my_put_nbr(va_arg(ag, int)));
}

int	my_print_bin(va_list ag)
{
  return (my_putnbr_base_u(va_arg(ag, unsigned int), "01"));
}

int	my_print_hexa_lower(va_list ag)
{
  return (my_putnbr_base_u(va_arg(ag, unsigned int), "0123456789abcdef"));
}

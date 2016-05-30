/*
** my_printf_function_3.c for  in /home/jean_j/rendu/PSU_2015/PSU_2015_my_printf
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Thu Nov  5 09:38:00 2015 jean jonathan
** Last update Mon Nov 23 17:56:07 2015 JEAN Jonathan
*/

#include <stdarg.h>
#include "my.h"

int	my_print_non_printable(va_list ag)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  j = 0;
  str = va_arg(ag, char*);
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  j += my_putchar('\\');
	  if (str[i] < 8)
	    j += my_putstr("00");
	  else if (str[i] < 64)
	    j += my_putchar('0');
	  j += my_putnbr_base(str[i], "01234567");
	}
      else
	j += my_putchar(str[i]);
      i++;
    }
  return (j);
}

int	my_print_float(va_list ag)
{
  return (my_put_float(va_arg(ag, double)));
}

int	my_print_long(va_list ag)
{
  return (my_putnbr_base_long(va_arg(ag, long), "0123456789"));
}

int     my_print_hexa_lower_s(va_list ag)
{
  int	i;

  i = my_putstr("0x");
  i += my_putnbr_base_u(va_arg(ag, unsigned int), "0123456789abcdef");
  return (i);
}

int     my_print_hexa_upper_s(va_list ag)
{
  int	i;

  i = my_putstr("0x");
  i += my_putnbr_base_u(va_arg(ag, unsigned int), "0123456789ABCDEF");
  return (i);
}

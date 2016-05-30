/*
** my_printf.c for  in /home/jean_j/rendu/PSU_2015/PSU_2015_my_printf
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Wed Nov  4 10:18:42 2015 jean jonathan
** Last update Mon Nov 23 17:55:42 2015 JEAN Jonathan
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

  /*
    %#x (0x)
    %5d
    %n
  */

t_fp	*init_format()
{
  t_fp	*fp_format;

  fp_format = malloc(sizeof(t_fp *) * MAX_SPEC);
  if (fp_format == NULL)
    return (NULL);
  fp_format[SPEC_C_LOWER] = my_print_char;
  fp_format[SPEC_S_LOWER] = my_print_str;
  fp_format[SPEC_D_LOWER] = my_print_int;
  fp_format[SPEC_I_LOWER] = my_print_int;
  fp_format[SPEC_B_LOWER] = my_print_bin;
  fp_format[SPEC_X_LOWER] = my_print_hexa_lower;
  fp_format[SPEC_X_UPPER] = my_print_hexa_upper;
  fp_format[SPEC_O_LOWER] = my_print_octal;
  fp_format[SPEC_B_UPPER] = my_print_bool;
  fp_format[SPEC_P_LOWER] = my_print_address;
  fp_format[SPEC_U_LOWER] = my_print_unsigned;
  fp_format[SPEC_S_UPPER] = my_print_non_printable;
  fp_format[SPEC_F_LOWER] = my_print_float;
  fp_format[SPEC_L_LOWER] = my_print_long;
  fp_format[SPEC_X_L_SPE] = my_print_hexa_lower_s;
  fp_format[SPEC_X_U_SPE] = my_print_hexa_upper_s;
  return (fp_format);
}

int	check_format(const char *str, int i, va_list ag)
{
  t_fp	*fp_format;
  char 	*specifier;
  int 	j;

  specifier = "csdibxXoBpuSflxX";
  j = 0;
  fp_format = init_format();
  if (str[i] == '#')
    if (str[++i] == 'x' || str[i] == 'X')
      j = 13;
  while (specifier[j] != '\0')
    {
      if (str[i] == specifier[j])
	return (fp_format[j](ag));
      j++;
    }
  if (str[i + 1] == 'd')
    return (fp_format[SPEC_D_LOWER](ag));
  j = my_putchar('%');
  if (str[i] == '#')
    j += my_putchar('#');
  j += my_putchar(str[i]);
  free(fp_format);
  return (j);
}

int	is_double(const char *str, int i)
{
  char	*spec_d;
  int	j;

  j = 0;
  spec_d = "csdibxXoBpuSfl";
  if (i > 1)
    {
      if (str[i - 2] == '%')
	{
	  while (spec_d[j] != '\0')
	    {
	      if (spec_d[j] == str[i])
		return (1);
	      j++;
	    }
	}
    }
  return (0);
}

int     my_printf(const char *str, ...)
{
  va_list       ag;
  int           i;
  int		count;

  va_start(ag, str);
  count = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '%')
        {
          i++;
	  if (str[i] == '%')
	    count += my_putchar(str[i]);
	  else
	    count += check_format(str, i, ag);
        }
      else
	if (is_double(str, i) == 0)
	  count += my_putchar(str[i]);
      i++;
    }
  va_end(ag);
  return (count);
}

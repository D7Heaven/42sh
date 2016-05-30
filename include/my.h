/*
** my.h for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_my_printf
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Fri Nov 13 14:11:22 2015 JEAN Jonathan
** Last update Sun Jan 24 12:43:58 2016 JEAN Jonathan
*/

#include <stdarg.h>

#ifndef MY_H_
#define MY_H_

#define READ_SIZE (1)
#define MAX_SPEC      16
#define SPEC_C_LOWER  0
#define SPEC_S_LOWER  1
#define SPEC_D_LOWER  2
#define SPEC_I_LOWER  3
#define SPEC_B_LOWER  4
#define SPEC_X_LOWER  5
#define SPEC_X_UPPER  6
#define SPEC_O_LOWER  7
#define SPEC_B_UPPER  8
#define SPEC_P_LOWER  9
#define SPEC_U_LOWER  10
#define SPEC_S_UPPER  11
#define SPEC_F_LOWER  12
#define SPEC_L_LOWER  13
#define SPEC_X_L_SPE  14
#define SPEC_X_U_SPE  15

typedef int (*t_fp)(va_list);

int	my_getnbr(char *);
int	my_strncmp(char *s1, char *s2, int n);
char	*lower_str(char *s1);
int	my_strcmp(char *s1, char *s2);
int	my_casecmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *src);
int	my_print_char(va_list ag);
int	my_print_str(va_list ag);
int	my_print_int(va_list ag);
int	my_print_bin(va_list ag);
int	my_print_hexa_lower(va_list ag);
int	my_print_hexa_upper(va_list ag);
int	my_print_hexa_lower_s(va_list ag);
int	my_print_hexa_upper_s(va_list ag);
int	my_print_octal(va_list ag);
int	my_print_bool(va_list ag) ;
int	my_print_address(va_list ag);
int	my_print_unsigned(va_list ag);
int	my_print_non_printable(va_list ag);
int	my_print_float(va_list ag);
int	my_print_long(va_list ag);
int	my_putchar(char c);
char	*my_memset(char *, char *, int);
int	my_strcat(char *, char *);
int	my_strlen(char *str);
int	my_putstr(char *str);
int	my_put_nbr(int nb);
int	my_put_nbr_unsigned(unsigned int nb);
int	my_putnbr_base(int nbr, char *base);
int	my_putnbr_base_long(long nbr, char *base);
int	my_putnbr_base_u(unsigned int nbr, char *base);
int	my_printf(const char *str, ...);
int	my_put_float(double nbr);
char	**my_cut_in_tab(char *, char);
char	*get_next_line(const int fd);
char	*my_rms(char *);
#endif

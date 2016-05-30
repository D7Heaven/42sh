/*
** my_putchar.c for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_my_printf
**
** Made by JEAN Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Fri Nov 13 14:09:44 2015 JEAN Jonathan
** Last update Fri Nov 13 14:10:15 2015 JEAN Jonathan
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}

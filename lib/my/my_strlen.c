/*
** my_strlen.c for my_strlen in /home/jean_j/day04
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Thu Oct  1 10:44:23 2015 jean jonathan
** Last update Fri Nov 13 14:09:35 2015 JEAN Jonathan
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*str != '\0')
    {
      i++;
      str++;
    }
  return (i);
}

/*
** my_strncmp.c for my_strncmp in /home/jean_j/rendu/Piscine_C_J06/ex_07
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Mon Oct  5 13:31:25 2015 jean jonathan
** Last update Mon Jan 25 12:30:00 2016 JEAN Jonathan
*/

#include <stdio.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  if (s1 == NULL || s1 == NULL)
    return (-1);
  if (my_strlen(s1) < n)
    return (-1);
  n--;
  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
    i++;
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  else
    return (s1[i] - s2[i]);
}

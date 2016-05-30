/*
** my_strcmp.c for my_strcmp in /home/jean_j/rendu/Piscine_C_J06/ex_06
** 
** Made by jean jonathan
** Login   <jean_j@epitech.net>
** 
** Started on  Mon Oct  5 12:49:46 2015 jean jonathan
** Last update Mon Oct  5 13:56:06 2015 jean jonathan
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    i++;
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  else
    return (s1[i] - s2[i]);
}

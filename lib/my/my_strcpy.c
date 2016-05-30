/*
** my_strcpy.c for my_strcpy in /home/jean_j/rendu/Piscine_C_J06/ex_02
**
** Made by jean jonathan
** Login   <jean_j@epitech.net>
**
** Started on  Mon Oct  5 09:01:26 2015 jean jonathan
** Last update Wed Jan  6 16:53:28 2016 JEAN Jonathan
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}

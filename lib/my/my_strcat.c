/*
** my_strcat.c for my_strcat.c in /home/picot_a/rendu/day07
**
** Made by vincent1 picot
** Login   <picot_a@epitech.net>
**
** Started on  Tue Oct  6 10:12:51 2015 vincent1 picot
** Last update Tue Jan  5 16:56:14 2016 JEAN Jonathan
*/

char	*my_strcat(char *s, char *t)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s[i] != '\0')
    i++;
  while ((s[i++] = t[j++]) != '\0')
    {
    }
}

/*
** match.c for 42sh in /home/tonell-m/rendu/PSU/42sh
**
** Made by tonell_m
** Login   <tonell-m@epitech.net>
**
** Started on  Mon May 30 13:58:25 2016 tonell_m
** Last update Mon May 30 14:13:09 2016 tonell_m
*/

int		match(char *s1, char *s2)
{
  if (*s1 != '\0' && *s2 == '*')
    return (match(s1 + 1, s2) || match(s1, s2 + 1));
  if (*s1 == '\0' && *s2 == '*')
    return (match(s1, s2 + 1));
  if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    return (match(s1 + 1, s2 + 1));
  if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
    return (1);
  return (0);
}

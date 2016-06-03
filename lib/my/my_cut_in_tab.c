/*
** my_cut_in_tab.c for 42 in /home/tonell-m/rendu/PSU/42sh
**
** Made by tonell_m
** Login   <tonell-m@epitech.net>
**
** Started on  Fri Jun  3 13:38:01 2016 tonell_m
** Last update Fri Jun  3 13:51:09 2016 tonell_m
*/

#include <stdlib.h>

int		how_many_words(char *str, char s)
{
  int		inhib;
  int		i;
  int		words;

  words = 0;
  i = 0;
  while (str[i])
    {
      inhib = 0;
      while (str[i] == s)
	i++;
      if (str[i] == 0)
	return (words);
      while ((str[i] != s || inhib % 2 == 1) && str[i])
	{
	  if (str[i] == '\"' || str[i] == '\'' || str[i] == '`')
	    inhib++;
	  i++;
	}
      words++;
    }
  return (words);
}

int		fill_tab(char *str, char **wordtab, int *i, int lenght)
{
  int		index;

  index = 0;
  while (lenght > 0)
    {
      wordtab[i[1]][index] = str[i[0] - lenght];
      lenght--;
      index++;
    }
  wordtab[i[1]][index] = '\0';
  return (EXIT_SUCCESS);
}

int		allocate_each_tab(char *str, char **wordtab, char s)
{
  int		i[2];
  int		lenght;
  int		inhib;

  i[0] = 0;
  i[1] = 0;
  while (str[i[0]] != 0)
    {
      inhib = 0;
      while (str[i[0]] == s)
	(i[0])++;
      if (str[i[0]] == 0)
	return (EXIT_SUCCESS);
      lenght = 0;
      while ((str[i[0]++] != s || inhib % 2 == 1) && str[i[0] - 1] != 0)
	{
	  if (str[i[0] - 1] == '\"' || str[i[0] - 1] == '\'' ||
	      str[i[0] - 1] == '`')
	    inhib++;
	  lenght++;
	}
      (i[0])--;
      if ((wordtab[i[1]] = malloc(sizeof(char) * lenght + 1)) == NULL)
	return (EXIT_FAILURE);
      fill_tab(str, wordtab, i, lenght);
      (i[1])++;
    }
  return (EXIT_SUCCESS);
}

char		**my_cut_in_tab(char *str, char s)
{
  char		**wordtab;
  int		words;

  if (str == NULL)
    return (NULL);
  words = how_many_words(str, s);
  if ((wordtab = malloc(sizeof(char *) * words + 8)) == NULL)
    return (NULL);
  if (allocate_each_tab(str, wordtab, s) == EXIT_FAILURE)
    return (NULL);
  wordtab[words] = NULL;
  return (wordtab);
}

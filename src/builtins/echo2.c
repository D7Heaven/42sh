/*
** echo2.c for  in /home/bedel_a/Projet/PSU/42sh
**
** Made by
** Login   <bedel_a@epitech.net>
**
** Started on  Wed Jun  1 20:00:05 2016
** Last update Wed Jun  1 20:00:26 2016 
*/

#include "sh.h"

int             check_parentheses(char *str)
{
  int           simple_quote;
  int           double_quote;
  int           i;

  i = 0;
  simple_quote = 0;
  double_quote = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\'')
	simple_quote++;
      if (str[i] == '\"')
	double_quote++;
      i++;
    }
  if (simple_quote % 2 == 1 || double_quote % 2 == 1)
    return (-1);
  if (simple_quote > 0 || double_quote > 0)
    return (1);
  return (0);
}

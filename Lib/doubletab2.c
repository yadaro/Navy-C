/*
** doubletab2.c for doubletab2 in /home/Yadaro/CPE_2016_BSQ
**
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
**
** Started on  Wed Dec 14 12:54:45 2016 Yadaro YUN
** Last update Sat Feb 18 21:17:11 2017 Yadaro YUN
** Last update Thu Feb  2 17:48:17 2017 Yadaro YUN
*/

#include "my.h"

int	y_line(char *str, char param)
{
  int	nb;
  int	c;

  if (str == NULL)
    return (84);
  nb = 0;
  c = 0;
  while (str[c])
    {
      if (str[c] == param)
	nb++;
      nb++;
      c++;
    }
  return (nb);
}

int	x_length(char *str, char param)
{
  int	c;

  if (str == NULL)
    return (84);
  c = 0;
  while (str[c] != param && str[c] != '\0')
      c = c + 1;
  return (c);
}

char	**my_str_to_wordtab2(char **tab, char *str, char param)
{
  int	x;
  int	y;
  int	c;

  y = 0;
  c = 0;
  if ((tab = malloc(sizeof(char*) * y_line(str, param) + 1)) == NULL)
    return (NULL);
  while (str[c] != '\0')
    {
      if ((tab[y] = malloc(sizeof(char) * (x_length(str, param) + 1))) == NULL)
	return (NULL);
      x = 0;
      while (str[c] != param && str[c] != '\0')
	{
	  tab[y][x] = str[c];
	  c = c + 1;
	  x = x + 1;
	}
      tab[y][x] = '\0';
      c = c + 1;
      y = y + 1;
    }
  tab[y] = NULL;
  return (tab);
}

char	**my_str_to_wordtab(char *str, char param)
{
  if (str == NULL)
    return (NULL);
  return (my_str_to_wordtab2(NULL, str, param));
}

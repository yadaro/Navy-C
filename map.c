/*
** map.c for  in /home/riusma/Documents/PSU_2017_navy/
**
** Made by Marius DAMIEN
** Login   <marius.damien@epitech.eu>
**
** Started on  Thu Feb  2 14:08:34 2017 Marius DAMIEN
** Last update Sun Feb 19 23:00:09 2017 Marius DAMIEN
*/

#include "my.h"

int	my_showtab(char **str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (84);
  while (str[i] != '\0')
    {
      my_putstr(str[i]);
      my_putchar('\n');
      i++;
    }
  return (0);
}

char	**create_map()
{
  int	i;
  char	**map;
  int	fd;
  char	*buf;

  if ((fd = open("map.txt", O_RDONLY)) == -1)
    return (NULL);
  if ((buf = malloc(sizeof(char) * 300)) == NULL)
    return (NULL);
  if ((i = read (fd, buf, 300)) == -1)
    return (NULL);
  buf[i + 1] = '\0';
  map = my_str_to_wordtab(buf, '\n');
  return (map);
}

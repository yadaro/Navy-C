/*
** hit.c for  in /home/riusma/Documents/Semestre_2/PSU/PSU_2016_navy/
**
** Made by Marius DAMIEN
** Login   <marius.damien@epitech.eu>
**
** Started on  Thu Feb 16 00:28:40 2017 Marius DAMIEN
** Last update Sun Feb 19 22:58:29 2017 Marius DAMIEN
*/

#include "my.h"

char	**hit_or_not(char **map, int u)
{
  int	x;
  int	y;

  if (map == NULL)
    return (NULL);
  x = u % 10;
  y = u / 10;
  my_putchar(y / 2 + 64);
  my_putchar(x + 48);
  if (g_i == 1)
    {
      my_putstr(": hit\n\n");
      map[x + 1][y]  = 'x';
    }
  else
    {
      my_putstr(": missed\n\n");
      if (map[x + 1][y] == 'x')
	map[x + 1][y] = 'x';
      else
	map[x + 1][y] = 'o';
    }
  g_i = 0;
  return (map);
}

char	**hit_or_not_termi2(char **map, int pid)
{
  int	x;
  int	y;

  x = g_i % 10;
  y = g_i / 10;
  my_putchar(y / 2 + 64);
  my_putchar(x + 48);
  if ((map[x + 1][y] == '2') || (map[x + 1][y] == '3') ||
      (map[x + 1][y] == '4') || (map[x + 1][y] == '5'))
    {
      map[x + 1][y]  = 'x';
      my_putstr(": hit\n\n");
      if (kill(pid, SIGUSR1) == -1)
	return (NULL);
    }
  else
    {
      map[x + 1][y] = 'o';
      my_putstr(": missed\n\n");
      if (kill(pid, SIGUSR2) == -1)
	return (NULL);
    }
  g_i = 0;
  return (map);
}

char	**hon(char **map, int pid)
{
  if (map == NULL)
    return (NULL);
  return (hit_or_not_termi2(map, pid));
}

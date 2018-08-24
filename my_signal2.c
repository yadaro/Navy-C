/*
** my_signal2.c for  in /home/riusma/Documents/Semestre_2/PSU/PSU_2016_navy/
**
** Made by Marius DAMIEN
** Login   <marius.damien@epitech.eu>
**
** Started on  Thu Feb 16 17:28:34 2017 Marius DAMIEN
** Last update Sun Feb 19 23:01:24 2017 Marius DAMIEN
*/

#include "my.h"

int	init_signal_user1(char **av, int pid)
{
  char	**map;
  char	**tab2;
  char	**map_init;

  g_i = 0;
  tab2 = NULL;
  map = create_map();
  map_init = create_map();
  tab2 = init_boat(av[1]);
  map = final_init(map, tab2);
  if (map == NULL || tab2 == NULL || map_init == NULL || av == NULL)
    return (84);
  my_putstr("enemy connected\n");
  while (g_i >= 0)
    graphic_user1(map, map_init, pid);
  return (0);
}

int	graphic_user1(char **map, char **map_init, int pid)
{
  int	ret;

  if (map == NULL || map_init == NULL)
    return (84);
  ret = 0;
  my_putstr("\nmy positions:\n");
  my_showtab(map);
  my_putstr("\nenemy's positions:\n");
  my_showtab(map_init);
  my_putchar('\n');
  ret = a_players(pid);
  usleep(2000);
  map_init = hit_or_not(map_init, ret);
  my_putstr("waiting for enemy's connexion...\n");
  timer();
  map = hit_or_not_termi2(map, pid);
  return (0);
}

int	init_signal_user2(char **av)
{
  char	**map;
  char	**tab2;
  char	**map_init;

  if (av == NULL)
    return (84);
  map = create_map();
  map_init = create_map();
  tab2 = init_boat(av[2]);
  map = final_init(map, tab2);
  while (g_i >= 0)
      graphic_user2(map, map_init, tab2, av);
  return (0);
}

int	graphic_user2(char **map, char **map_init, char **tab2, char **av)
{
  int	ret;
  int	pid;

  pid = my_atoi(av[1]);
  ret = 0;
  if (map == NULL || tab2 == NULL || map_init == NULL || av == NULL)
    return (84);
  my_showtab(map);
  my_putchar('\n');
  my_putstr("enemy's positions:\n");
  my_showtab(map_init);
  my_putchar('\n');
  my_putstr("waiting for enemy's attack...\n");
  timer();
  map = hit_or_not_termi2(map, pid);
  usleep(2000);
  ret = a_players(pid);
  usleep(2000);
  map_init = hit_or_not(map_init, ret);
  return (0);
}

/*
** boat_placement.c for  in /home/riusma/Documents/Semestre_2/PSU/PSU_2016_navy/
**
** Made by Marius DAMIEN
** Login   <marius.damien@epitech.eu>
**
** Started on  Mon Feb  6 10:49:06 2017 Marius DAMIEN
** Last update Sun Feb 19 22:56:00 2017 Marius DAMIEN
*/

#include "my.h"

char	conversion_table(char c)
{
  c = (c == 'A' || c == 'a') ? 2 : c;
  c = (c == 'B' || c == 'b') ? 4 : c;
  c = (c == 'C' || c == 'c') ? 6 : c;
  c = (c == 'D' || c == 'd') ? 8 : c;
  c = (c == 'E' || c == 'e') ? 10 : c;
  c = (c == 'F' || c == 'f') ? 12 : c;
  c = (c == 'G' || c == 'g') ? 14 : c;
  c = (c == 'H' || c == 'h') ? 16 : c;
  if (c == 0)
    return (84);
  return (c);
}

char	**init_boat(char *av)
{
  int	fd;
  char	**first_map;
  char	*buf;
  int	i;
  int	a;

  i = 0;
  if ((fd =  open(av , O_RDONLY)) == -1)
    return (NULL);
  if ((buf = malloc(sizeof(char) * READ_SIZE)) == NULL)
    return (NULL);
  if (av == NULL || buf == NULL)
    return (NULL);
  if ((a = read(fd, buf, READ_SIZE)) == -1)
    return (NULL);
  buf[a + 1] = '\0';
  first_map = my_str_to_wordtab(buf, '\n');
  while (buf[i] != '\0' && first_map[i] != '\0')
    {
      first_map[i][2] = conversion_table(first_map[i][2]);
      first_map[i][5] = conversion_table(first_map[i][5]);
      i = i + 1;
    }
  close(fd);
  free(buf);
  return (first_map);
}

char	**feel_boat(char **tab, char **tab2, int i, int k)
{
  int	a;

  a = k - 1;
  if (tab == NULL || tab2 == NULL)
    return (NULL);
  while (a != 0)
    {
       if ((tab2[i][3] - 47) == (tab2[i][6] - 47))
         {
	   tab[tab2[i][3] - 47][tab2[i][2]] = k + 48;
           tab2[i][2] = tab2[i][2] + 2;
           a = a - 1;
         }
       if (((tab2[i][2]) == (tab2[i][5])) && (a != 0))
         {
           tab[tab2[i][3] - 47][tab2[i][2]] = k + 48;
           tab2[i][3] = tab2[i][3] + 1;
           a = a - 1;
	}
    }
  return (tab);
}

char	**final_init(char **tab, char **tab2)
{
  int	i;
  int	k;

  i = 0;
  k = 2;
  if (tab == NULL || tab2 == NULL)
    return (NULL);
  while (i <= 3)
    {
      tab = feel_boat(tab, tab2, i, k);
      tab[tab2[i][3] - 47][tab2[i][2]] = k + 48;
      i = i + 1;
      k = k + 1;
    }
  return (tab);
}

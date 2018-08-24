/*
** notice.c for Navy in /home/Yadaro/PSU_2016_navy
**
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
**
** Started on  Mon Jan 30 18:31:11 2017 Yadaro YUN
** Last update Sun Feb 19 22:58:48 2017 Marius DAMIEN
*/

#include "my.h"

void	notice()
{
  my_putstr("USAGE\n\t ./navy [first_player_pid] navy_positions\n\n");
  my_putstr("DESCRIPTION\n\tfirst_player_pid\tonly for the 2nd player. ");
  my_putstr("pid for the first player.\n\tnavy positions\t");
  my_putstr("\tfile representing the positions of the ships.\n");
}

int	two_arg(char **av)
{
  if (my_strcmp(av[1], "-h") == 0)
    {
      notice();
      return (0);
    }
  else if (av[1][0] == '-' && av[1][1] != 'h')
    {
      my_errstr("Bad flag\n");
      return (84);
    }
  else if (open_file(av[1]) != 0 && open_file(av[1]) != 84)
    {
      my_signal(av);
      my_putstr("attack: ");
    }
  else if (open_file(av[1]) == 84)
    {
      my_errstr("Bad arguments\n");
      return (84);
    }
  return (0);
}

int	conditions(int ac)
{
  if (ac == 1)
    {
      my_errstr("Need arguments\n");
      return (84);
    }
  else if (ac > 3)
    {
      my_errstr("Too much arguments\n");
      return (84);
    }
  return (0);
}

int	open_file(char *file)
{
  int	fd;
  char	buff[READ_SIZE + 1];
  int	rd;
  char	*str;

  if (file == NULL)
    return (84);
  if ((str = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (84);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (84);
  if ((rd = read(fd, buff, READ_SIZE)) == -1)
    return (84);
  close(fd);
  free(str);
  return (rd);
}

int	main(int ac, char **av)
{
  conditions(ac);
  if (ac ==  2)
    two_arg(av);
  if (ac == 3)
    {
      if (open_file(av[2]) != 0 && open_file(av[2]) != 84)
	my_second_signal(ac, av);
      else if (open_file(av[2]) == 84)
	{
	  my_errstr("Invalid pos or bad arguments\n");
	  return (84);
	}
    }
  return (0);
}

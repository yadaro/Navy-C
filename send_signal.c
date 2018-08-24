/*
** send_signal.c for Navy in /home/Yadaro/PSU_2016_navy
**
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
**
** Started on  Sat Feb 18 20:12:43 2017 Yadaro YUN
** Last update Sun Feb 19 23:01:39 2017 Marius DAMIEN
*/

#include "my.h"

int	send_signal(char *s, int pid)
 {
  int	x;
  int	y;
  int	ret;

  ret = 0;
  if (s == NULL)
    return (84);
  if (s[0] >= '1' && s[0] <= '8')
    {
      y = conversion_table(s[1]);
      x = s[0] - 48;
    }
  if (s[1] >= '1' && s[1] <= '8')
    {
      y = conversion_table(s[0]);
      x = s[1] - 48;
    }
  y = send_signal16(y, pid);
  x = send_signal8(x, pid);
  ret = y * 10 + x;
  return (ret);
}


int	send_signal16(int y, int pid)
{
  int	i;

  i = 1;
  while (i <= 16)
    {
      if (i <= y)
	{
	  usleep(2000);
	  if ((kill(pid, SIGUSR1)) == -1)
	  return (84);
	}
      else
	{
	  usleep(2000);
	  if ((kill(pid, SIGUSR2)) == -1)
	  return (84);
	}
      i = i + 1;
    }
  return (y);
}

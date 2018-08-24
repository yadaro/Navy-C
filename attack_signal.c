/*
** attack_signal.c for  in /home/riusma/Documents/Semestre_2/PSU/PSU_2016_navy/
**
** Made by Marius DAMIEN
** Login   <marius.damien@epitech.eu>
**
** Started on  Mon Feb 13 19:02:29 2017 Marius DAMIEN
** Last update Sun Feb 19 18:48:49 2017 Yadaro YUN
*/

#include "my.h"
#include "gnl.h"

static int	n = 1;
static int	safe = 0;

void	attack1(int sig, siginfo_t *ptr, void *contxt)
{
  (void) sig;
  (void) ptr;
  (void) contxt;

  g_i = g_i + 1;
  if (n == 16)
    g_i = g_i * 10;
  n = n + 1;
}

void	attack2(int sig, siginfo_t *ptr, void *contxt)
{
  (void) sig;
  (void) ptr;
  (void) contxt;

  g_i = g_i;
  if (n == 16)
    g_i = g_i * 10;
  n = n + 1;
}

int	send_signal8(int x, int pid)
{
  int	i;

  i = 0;
  while (i < 8)
    {
      if (i < x)
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
      n = 0;
    }
  return (x);
}

int	a_players(pid_t pid)
{
  char	*s;
  int	ret;

  ret = 0;
  my_putstr("attack : ");
  s = get_next_line(0);
  if (my_strlen(s) == 2)
    {
      verif_coord(pid, &ret, s);
      return (ret);
    }
  else
    {
      my_putstr("Too many or few arguments\n");
      safe++;
      ret = a_players(pid);
    }
  while (safe > 0)
    {
      safe--;
      return (ret);
    }
  free(s);
  return (ret);
}

void	verif_coord(int pid, int *ret, char *s)
{
  if ((s[0] >= 'A' && s[0] <= 'H' && s[1] >= '1' && s[1] <= '8')
      || (s[1] >= 'A' && s[1] <= 'H' && s[0] >= '1' && s[0] <= '8'))
    *ret = send_signal(s, pid);
  else if ((s[0] >= 'a' && s[0] <= 'h' && s[1] >= '1' && s[1] <= '8')
	   || (s[1] >= 'a' && s[1] <= 'h' && s[0] >= '1' && s[0] <= '8'))
    *ret = send_signal(s, pid);
  else
    {
      my_putstr("Wrong position\n");
      safe++;
      *ret = a_players(pid);
    }
}

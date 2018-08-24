/*
** my_signal.c for Navy in /home/Yadaro/PSU_2016_navy
**
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
**
** Started on  Wed Feb  1 12:00:27 2017 Yadaro YUN
** Last update Sat Feb 18 19:55:32 2017 Yadaro YUN
*/

#include "my.h"

void	hdl(int sig, siginfo_t *sinfo, void *contxt)
{
  (void) sig;
  (void) contxt;
  g_i = sinfo->si_pid;
}

int			my_signal(char **av)
{
  struct sigaction	new;
  struct sigaction	old;
  struct sigaction	yun;
  int			pid;

  new.sa_flags = SA_SIGINFO;
  new.sa_sigaction = &hdl;
  old.sa_flags = SA_SIGINFO;
  old.sa_sigaction = &attack2;
  yun.sa_flags = SA_SIGINFO;
  yun.sa_sigaction = &attack1;
  sigaction(SIGUSR2, &old, NULL);
  my_putstr("my_pid:\t");
  my_put_nbr(getpid());
  my_putstr("\nwaiting for enemy connexion...\n");
  sigaction(SIGUSR1, &new, NULL);
  while (g_i == 0);
  pid = g_i;
  sigaction(SIGUSR1, &yun, NULL);
  init_signal_user1(av, pid);
  return (0);
}

int			my_second_signal(int ac, char **av)
{
  struct sigaction	att;
  struct sigaction	other;
  pid_t			pid;

  att.sa_flags = SA_SIGINFO;
  att.sa_sigaction = &attack1;
  other.sa_flags = SA_SIGINFO;
  other.sa_sigaction = &attack2;
  sigaction(SIGUSR2, &other, NULL);
  pid = my_atoi(av[1]);
  if (kill(pid, SIGUSR1) == -1)
    {
      my_errstr("Bad token\n");
      return (84);
    }
  my_putstr("my_pid:\t");
  my_put_nbr(getpid());
  my_putchar('\n');
  my_putstr("successfully connected\n\n");
  my_putstr("my positions:\n");
  sigaction(SIGUSR1, &att, NULL);
  if (ac == 3)
    init_signal_user2(av);
  return (0);
}

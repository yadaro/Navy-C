/*
** my_putstr.c for Navy in /home/Yadaro/PSU_2016_navy
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Mon Jan 30 18:32:00 2017 Yadaro YUN
** Last update Fri Feb 10 16:45:21 2017 Yadaro YUN
*/

#include "my.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}

int	my_putstr(char *s)
{
  int	i;

  i = 0;
  if (s == NULL)
    return (84);
  while (s[i])
    {
      my_putchar(s[i]);
      i++;
    }
  return (0);
}

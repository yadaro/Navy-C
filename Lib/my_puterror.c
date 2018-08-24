/*
** my_puterror.c for Navy in /home/Yadaro/PSU_2016_navy
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Thu Feb  2 09:42:21 2017 Yadaro YUN
** Last update Wed Feb 15 16:24:17 2017 Yadaro YUN
*/

#include "my.h"

void	my_errchar(char c)
{
  write (2, &c, 1);
}

int	my_errstr(char *s)
{
  int	i;

  i = 0;
  if (s == NULL)
    return (84);
  while (s[i] != '\0')
    {
      my_errchar(s[i]);
      i++;
    }
  return (0);
}

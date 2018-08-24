/*
** my_atoi.c for my_atoi in /home/Yadaro/CPE_2016_Pushswap
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Fri Nov 25 09:50:06 2016 Yadaro YUN
** Last update Thu Feb  2 12:57:51 2017 Yadaro YUN
*/

#include "my.h"

int	my_atoi(char *str)
{
  int	res;
  int	i;

  i = 0;
  res = 0;
  if (str == NULL)
    return (84);
  while (str[i])
    {
      res = res * 10 + str[i] - 48;
      i++;
    }
  return (res);
}


/*
** my_put_nbr.c for my_put_nbr.c in /home/Yadaro/CPool_Day03
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Thu Nov  3 15:59:01 2016 Yadaro YUN
** Last update Fri Feb 17 16:28:57 2017 Yadaro YUN
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb >= 0 && nb <= 9)
      my_putchar(nb + '0');
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      nb = nb % 10;
      my_putchar(nb + '0');
    }
  return (0);
}

/*
** my_strlen.c for Navy in /home/Yadaro/PSU_2016_navy/Lib
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Wed Feb  8 18:25:07 2017 Yadaro YUN
** Last update Wed Feb  8 18:26:12 2017 Yadaro YUN
*/

#include "my.h"

int	my_strlen(char *s)
{
  int	i;
  
  i = 0;
  if (s == NULL)
    return (84);
  while (s[i])
    i++;
  return (i);
}

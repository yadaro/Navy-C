/*
** my_strcmp.c for my_strcmp.c in /home/Yadaro/CPool_Day06
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Fri Nov  4 15:37:22 2016 Yadaro YUN
** Last update Fri Feb 17 16:30:06 2017 Yadaro YUN
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  
  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (84);
  while (s1[i] == s2[i] && s1[i] != '\0' && s2 != '\0')
    i++;
  return (s1[i] - s2[i]);
}

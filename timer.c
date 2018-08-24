/*
** timer.c for  in /home/riusma/Documents/Semestre_2/PSU/PSU_2016_navy/
**
** Made by Marius DAMIEN
** Login   <marius.damien@epitech.eu>
**
** Started on  Sun Feb 12 18:35:39 2017 Marius DAMIEN
** Last update Sat Feb 18 20:26:42 2017 Yadaro YUN
*/

#include "my.h"

void	timer()
{
  int	i;

  i = 24;
  while (i > 0)
    {
      pause();
      i--;
    }
}

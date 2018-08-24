/*
** my.h for print_commands in /home/Yadaro/bootcamp-minishell/print_commands
**
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
**
** Started on  Fri Jan 27 10:01:39 2017 Yadaro YUN
** Last update Sun Feb 19 15:01:35 2017 Yadaro YUN
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef		_MY_H_
#define		_MY_H_

#define READ_SIZE 500

int	g_i;
void	stop_loop();
int	my_signal(char **av);
int	my_second_signal(int ac, char **av);
void	my_putchar(char c);
int	my_putstr(char *s);
int	my_put_nbr(int nb);
int	my_atoi(char *str);
int	my_strcmp(char *s1, char *s2);
void	my_errchar(char c);
int	my_errstr(char *s);
char	**create_map();
char	**my_str_to_wordtab2(char **tab, char *str, char param);
char	**my_str_to_wordtab(char *str, char param);
int	my_showtab(char **str);
void	hdl(int sig, siginfo_t *sinfo, void *contxt);
char	**init_boat(char *av);
char	**final_init(char **tab, char **tab2);
int	a_players(pid_t pid);
void	attack1(int sig, siginfo_t *ptr, void *contxt);
void	attack2(int sig, siginfo_t *ptr, void *contxt);
int	my_strlen(char *s);
char	conversion_table(char c);
int	open_file(char *file);
char	**hit_or_not(char **map, int u);
char	**hit_or_not_termi2(char **map, int pid);
int	graphic_user2(char **map, char **map_init, char **tab2, char **av);
int	graphic_user1(char **map, char **map_init, int pid);
int	init_signal_user2(char **av);
int	init_signal_user1(char **av, int pid);
void	timer();
int	send_signal(char *s, int pid);
int	send_signal16(int y, int pid);
int	send_signal8(int x, int pid);
void	verif_coord(int pid, int *ret, char *s);
char	**hon(char **map, int pid);

#endif		/*_MY_H_*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:12:48 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/10 16:49:20 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	bitcheck(int pid, char c)
{
	int	bit;
	int	kill_state;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit) & 1)
			kill_state = kill(pid, SIGUSR1);
		else
			kill_state = kill(pid, SIGUSR2);
		if (kill_state == -1)
			write(2, "kill fail\n", 10);
		usleep(300);
	}
}

void	handle(int sig)
{
	if (sig == SIGUSR1)
		my_putstr("well we finish printing !");
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3 || my_atoi(av[1]) <= 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else
	{
		pid = my_atoi(av[1]);
		i = 0;
		signal(SIGUSR1, handle);
		while (av[2][i])
		{
			bitcheck(pid, av[2][i]);
			i++;
		}
		bitcheck(pid, '\0');
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:35:20 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/10 16:47:58 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <unistd.h>

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

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac != 3 || my_atoi(av[1]) <= 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else
	{
		pid = my_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			bitcheck(pid, av[2][i]);
			i++;
		}
	}
}

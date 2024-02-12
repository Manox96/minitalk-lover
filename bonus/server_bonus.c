/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:11:42 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/12 15:16:37 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	printbits_on_a(int signum, int *a, int *b)
{
	if (signum == SIGUSR1)
		*a = (*a << 1) | 1;
	else if (signum == SIGUSR2)
		*a = *a << 1;
	(*b)++;
}

void	print_a(int *bit, int *a, int pidclient)
{
	if (*bit == 8)
	{
		if (*a == '\0')
			kill(pidclient, SIGUSR1);
		else
			write(1, a, 1);
		*a = 0;
		*bit = 0;
	}
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	a;
	static int	bit;
	static int	pidclient;

	(void) context;
	if (!pidclient)
		pidclient = info->si_pid;
	if (pidclient != info->si_pid)
	{
		pidclient = info->si_pid;
		bit = 0;
		a = 0;
	}
	printbits_on_a(signum, &a, &bit);
	print_a(&bit, &a, pidclient);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}

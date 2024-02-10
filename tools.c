/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:50:10 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/07 19:41:03 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "minitalk_bonus.h"
#include <unistd.h>

long	my_atoi(const char *str)
{
	int			i;
	long		s;
	long		r;

	r = 0;
	s = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		if ((r * s) > INT_MAX || (r * s) < INT_MIN)
			exit(1);
		i++;
	}
	return (s * r);
}
void ft_putchar_fd(char c,int fd)
{
	write(fd,&c,1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = n * -1 ;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}
int my_strlen(char *str)
{
	int i;
	i = 0;

	while (str[i])
		i++;
	return (i);
}

void my_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1,&str[i],1);
		i++;
	}
}


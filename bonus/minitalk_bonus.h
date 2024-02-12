/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:14:37 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/07 19:40:20 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
#define MINITALK_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <stdlib.h>

long	my_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
int my_strlen(char *str);
void my_putstr(char *str);

#endif

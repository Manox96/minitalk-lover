/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:42:49 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/07 16:01:56 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <stdlib.h>

long	my_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
int my_strlen(char *str);

#endif

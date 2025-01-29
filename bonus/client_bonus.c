/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:00:04 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/29 11:56:36 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

int	g_wait_response = 0;

static void	handle_response(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("\033[0;32m✅ message recieved ✅\033[0m\n");
	g_wait_response = 1;
}

static void	send_bits(int pid, char *str)
{
	static int	bit;

	while (*str)
	{
		bit = 8;
		while (bit--)
		{
			g_wait_response = 0;
			if ((*str >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (!g_wait_response)
				;
		}
		str++;
	}
	bit = 8;
	while (bit--)
	{
		g_wait_response = 0;
		kill(pid, SIGUSR1);
		while (!g_wait_response)
			;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, handle_response);
	signal(SIGUSR2, handle_response);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_bits(pid, av[2]);
	}
	else
	{
		ft_printf("\033[0;31m❌ Syntaxe Error ❌\033[0m\n");
		return (1);
	}
	return (0);
}

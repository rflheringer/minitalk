/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:06:20 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/23 17:33:52 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_wait_response = 0;

static void	handle_response(int signal)
{
	(void)signal;
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

int	main(int ac, char **argv)
{
	int	pid;

	signal(SIGUSR1, handle_response);
	signal(SIGUSR2, handle_response);
	if (ac == 3)
	{
		pid = ft_atoi(argv[1]);
		send_bits(pid, argv[2]);
	}
	else
	{
		ft_printf("\033[1;31mError\033[0m\n");
		return (1);
	}
	return (0);
}

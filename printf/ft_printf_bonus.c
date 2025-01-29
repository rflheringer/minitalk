/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:47:34 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/23 13:50:53 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	unsigned int	count_chars;
	va_list			args;
	t_flags			flags;

	va_start(args, format);
	count_chars = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			ft_init_flags(&flags);
			format++;
			ft_check_flag_bonus(format, &flags);
			count_chars += ft_cap_type(format, args, &flags);
			while (ft_strchr(" +#", *format))
				format++;
		}
		else
			count_chars += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count_chars);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write (1, &s[i++], 1);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str + i);
	return (NULL);
}

void	ft_check_flag_bonus(const char *format, t_flags *flags)
{
	int	count;

	count = 0;
	while (format[count] == '#' || format[count] == '+' || format[count] == ' ')
	{
		if (format[count] == '#')
			flags->hash = 1;
		if (format[count] == '+')
			flags->plus = 1;
		if (format[count] == ' ')
			flags->space = 1;
		count++;
	}
}

void	ft_init_flags(t_flags *flags)
{
	flags->u = 0;
	flags->d = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
}

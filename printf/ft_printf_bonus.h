/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:57:45 by rheringe          #+#    #+#             */
/*   Updated: 2024/11/01 17:57:53 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct flags {
	unsigned int	u;
	int				d;
	int				hash;
	int				plus;
	int				space;
}	t_flags;

unsigned int	ft_putchar(int c);
unsigned int	ft_print_percent_sign(void);
unsigned int	ft_putnbr_base16(unsigned long n, char format, t_flags *flags);
unsigned int	ft_cap_type(const char *format, va_list args, t_flags *flags);
unsigned int	ft_decimal(unsigned int arg, t_flags *flags);
unsigned int	ft_ptr(void *ptr, t_flags *flags);
unsigned int	ft_putstr_count(char *s);
unsigned int	ft_putstr_aux(char *s);
void			ft_putnbr(int n, int fd);
void			ft_init_flags(t_flags *flags);
void			ft_check_flag_bonus(const char *format, t_flags *flags);
void			ft_putstr(char *s);
char			*ft_utoa(unsigned int n);
char			*ft_strchr(const char *str, int c);
char			*ft_itoa(int n);
int				ft_printf(const char *format, ...);
int				ft_count_n(long n);
int				ft_strlen(const char *c);

#endif
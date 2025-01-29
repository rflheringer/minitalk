/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:00:02 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/23 13:56:13 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_s;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join_s = (char *)malloc(((len_s1 + len_s2 + 1) * sizeof(char)));
	if (!join_s)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		join_s[i] = s1[i];
	j = 0;
	while ((j) < len_s2)
	{
		join_s[i] = s2[j];
		i++;
		j++;
	}
	join_s[i] = '\0';
	return (join_s);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

void	*ft_memset(void *str, int c, size_t n)
{
	int		i;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	while (n-- > 0)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s)
{	
	char	*copy;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

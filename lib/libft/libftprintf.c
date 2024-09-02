/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:11:47 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/02 17:46:50 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		i = 11;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		i = 1 + ft_putnbr(-1 * n);
	}
	else if (n >= 10)
	{
		i = ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
		i++;
	}
	else
	{
		ft_putchar(n + '0');
		i = 1;
	}
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i = ft_putnbr_u(n / 10);
		ft_putchar((n % 10) + '0');
		i++;
	}
	else
	{
		ft_putchar(n + '0');
		i = 1;
	}
	return (i);
}

int	ft_putnbr_hex(unsigned long int n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i = ft_putnbr_hex(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
	i++;
	return (i);
}

int	ft_putnbr_hex_upper(unsigned long int n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i = ft_putnbr_hex_upper(n / 16);
	ft_putchar("0123456789ABCDEF"[n % 16]);
	i++;
	return (i);
}

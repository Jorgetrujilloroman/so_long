/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:30:06 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/02 16:33:02 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

void	ft_printf_conv(const char **content, va_list args, int *count)
{
	if (**content == '%')
	{
		(*content)++;
		if (**content == 'c')
			*count += ft_putchar(va_arg(args, int));
		else if (**content == 's')
			*count += ft_putstr(va_arg(args, char *));
		else if (**content == 'p')
		{
			*count += ft_putstr("0x");
			*count += ft_putnbr_hex((unsigned long int)va_arg(args, void *));
		}
		else if (**content == 'd' || **content == 'i')
			*count += ft_putnbr(va_arg(args, int));
		else if (**content == 'u')
			*count += ft_putnbr_u(va_arg(args, unsigned int));
		else if (**content == 'x')
			*count += ft_putnbr_hex(va_arg(args, unsigned int));
		else if (**content == 'X')
			*count += ft_putnbr_hex_upper(va_arg(args, unsigned int));
		else if (**content == '%')
			*count += ft_putchar('%');
	}
	else
		*count += ft_putchar(**content);
}

int	ft_printf(char const *content, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, content);
	if (write(1, "", 0))
		return (-1);
	while (*content)
	{
		ft_printf_conv(&content, args, &count);
		content++;
	}
	va_end(args);
	if (write(1, "", 0) == -1)
		return (-1);
	else
		return (count);
}

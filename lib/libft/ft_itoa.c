/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:26:30 by jotrujil          #+#    #+#             */
/*   Updated: 2024/01/11 19:39:33 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chrlength(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
	{
		length++;
		n = n * -1;
	}
	while (n > 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*processmalloc(int length)
{
	char	*r;

	r = malloc((length * sizeof(char)) + 1);
	if (!r)
		return (NULL);
	return (r);
}

char	*exceptioncase(int n)
{
	char	*s;

	if (n == -2147483648)
	{
		s = ft_strdup("-2147483648");
		if (!s)
			return (NULL);
		return (s);
	}
	else
	{
		s = malloc(2);
		if (!s)
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		length;
	int		neg;

	neg = 0;
	if (n == -2147483648 || n == 0)
		return (exceptioncase(n));
	length = ft_chrlength(n);
	s = processmalloc(length);
	if (!s)
		return (NULL);
	if (n < 0)
		neg = 1;
	s[length] = '\0';
	if (neg)
		n = -n;
	while (n > 0)
	{
		length--;
		s[length] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-1234));
	printf("%s\n", ft_itoa(1234));
	printf("%s\n", ft_itoa(0));
	printf("%d\n", ft_chrlength(0));
	printf("%d\n", ft_chrlength(-1234));
} */
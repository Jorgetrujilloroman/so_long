/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:23:08 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/02 17:45:39 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(char const *content, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_hex(unsigned long int n);
int	ft_putnbr_hex_upper(unsigned long int n);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:01:49 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/08/08 21:43:33 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_convertion(char c, va_list args)
{
	int	sum;

	sum = 0;
	if (c == 'c')
		sum = ft_print_char(va_arg(args, int));
	else if (c == 's')
		sum = ft_print_string(va_arg(args, char *));
	else if (c == 'p')
		sum = ft_print_pointer(va_arg(args, unsigned long));
	else if (c == 'i' || c == 'd')
		sum = ft_print_number(va_arg(args, int));
	else if (c == 'u')
		sum = ft_print_unsigned_decimal(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		sum = ft_print_hex(c, va_arg(args, unsigned int));
	else if (c == '%')
		sum = ft_print_char('%');
	return (sum);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		sum;
	int		i;

	va_start (args, str);
	i = 0;
	sum = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			sum += ft_convertion(str[++i], args);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			sum++;
		}
	}
	va_end (args);
	return (sum);
}

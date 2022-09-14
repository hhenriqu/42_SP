/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:19:23 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/08/07 01:21:43 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	size_t	len;

	if (!str)
		len = write(1, "(null)", 6);
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	return (len);
}

int	ft_print_number(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_print_hex(char c, unsigned int n)
{
	size_t	len;
	char	hex[30];
	int		letters_offset;
	int		i;

	len = 0;
	if (c == 'X')
		letters_offset = 55;
	else
		letters_offset = 87;
	if (n == 0)
		return (write(1, "0", 1));
	while (n)
	{
		if (n % 16 > 9)
			hex[len++] = (n % 16) + letters_offset;
		else
			hex[len++] = (n % 16) + 48;
		n /= 16;
	}
	i = len - 1;
	while (i >= 0)
		write(1, &hex[i--], 1);
	return (len);
}

int	ft_print_pointer(unsigned long n)
{
	size_t	len;
	char	hex[26];
	int		i;

	len = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	while (n)
	{
		if (n % 16 > 9)
			hex[len++] = (n % 16) + 87;
		else
			hex[len++] = (n % 16) + 48;
		n /= 16;
	}
	i = len - 1;
	while (i >= 0)
		write(1, &hex[i--], 1);
	return (len + 2);
}

int	ft_print_unsigned_decimal(unsigned int n)
{
	int		i;
	char	unsign[10];
	size_t	len;

	i = 0;
	while (n > 9)
	{
		unsign[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	unsign[i] = n + 48;
	len = i + 1;
	while (i >= 0)
	{
		write(1, &unsign[i], 1);
		i--;
	}
	return (len);
}

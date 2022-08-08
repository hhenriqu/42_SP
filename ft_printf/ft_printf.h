/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:35:44 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/08/07 01:18:07 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_convertion(char c, va_list args);
int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_number(int n);
int	ft_print_hex(char c, unsigned int n);
int	ft_print_pointer(unsigned long n);
int	ft_print_unsigned_decimal(unsigned int n);

#endif
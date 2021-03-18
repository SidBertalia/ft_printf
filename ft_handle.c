/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbertali <sbertali@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:49:17 by sbertali          #+#    #+#             */
/*   Updated: 2021/03/18 12:25:22 by sbertali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspec(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_isflag(int c)
{
	return ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '));
}

int	ft_handle(int c, t_flags flags, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count = ft_handle_char(va_arg(args, int), flags);
	else if (c == '%')
		count += ft_handle_percent(flags);
	else if (c == 'p')
		count = ft_handle_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 's')
		count = ft_handle_string(va_arg(args, char *), flags);
	else if ((c == 'i') || (c == 'd'))
		count = ft_handle_int(va_arg(args, int), flags);
	else if (c == 'x')
		count += ft_handle_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_handle_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == 'u')
		count += ft_handle_unsigned((unsigned int)va_arg(args, unsigned int)
		, flags);
	return (count);
}

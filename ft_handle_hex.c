/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbertali <sbertali@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:49:52 by sbertali          #+#    #+#             */
/*   Updated: 2021/03/18 12:05:50 by sbertali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_hex(char *hex, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_handle_width(flags.dot - 1, ft_strlen(hex) - 1, 1);
	}
	count += ft_put_dot(hex, ft_strlen(hex));
	return (count);
}

static int	ft_put_hex(char *hex, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_get_hex(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_handle_width(flags.width, 0, 0);
	}
	else
	{
		count += ft_handle_width(flags.width, ft_strlen(hex), flags.zero);
	}
	if (flags.minus == 0)
		count += ft_get_hex(hex, flags);
	return (count);
}

int			ft_handle_hex(unsigned int number, int lowercase, t_flags flags)
{
	char	*hex;
	int		count;

	number = (unsigned int)(4294967295 + 1 + number);
	count = 0;
	if (flags.dot == 0 && number == 0)
	{
		count += ft_handle_width(flags.width, 0, 0);
		return (count);
	}
	hex = ft_utl_base((unsigned long long)number, 16);
	if (lowercase == 1)
		hex = ft_str_tolower(hex);
	count += ft_put_hex(hex, flags);
	free(hex);
	return (count);
}

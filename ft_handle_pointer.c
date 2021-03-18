/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbertali <sbertali@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:49:38 by sbertali          #+#    #+#             */
/*   Updated: 2021/03/18 12:13:11 by sbertali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_pointer(char *pointer, t_flags flags)
{
	int count;

	count = 0;
	count += ft_put_dot("0x", 2);
	if (flags.dot >= 0)
	{
		count += ft_handle_width(flags.dot, ft_strlen(pointer), 1);
		count += ft_put_dot(pointer, flags.dot);
	}
	else
		count += ft_put_dot(pointer, ft_strlen(pointer));
	return (count);
}

int			ft_handle_pointer(unsigned long long num, t_flags flags)
{
	int		count;
	char	*p;

	count = 0;
	if (flags.dot == 0 && !num)
	{
		if (flags.width >= 0 && flags.minus == 0)
			(((count += ft_handle_width(flags.width - 2, 0, 0))
			|| 1) && ((count += ft_put_dot("0x", 2)) || 1));
		else
			(((count += ft_put_dot("0x", 2)) || 1) &&
			((count += ft_handle_width(flags.width - 2, 0, 0)) || 1));
		return (count);
	}
	p = ft_utl_base(num, 16);
	p = ft_str_tolower(p);
	if ((size_t)flags.dot < ft_strlen(p))
		flags.dot = ft_strlen(p);
	if (flags.minus == 1)
		count += ft_get_pointer(p, flags);
	count += ft_handle_width(flags.width, ft_strlen(p) + 2, 0);
	if (flags.minus == 0)
		count += ft_get_pointer(p, flags);
	free(p);
	return (count);
}

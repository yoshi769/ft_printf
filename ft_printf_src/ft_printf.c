/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaso <yaso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:20:28 by yaso              #+#    #+#             */
/*   Updated: 2025/05/29 18:42:04 by yaso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_dealing_format(char c, va_list ap);

int	ft_printf(const char *param, ...)
{
	va_list	ap;
	int		count;
	int		i;

	if (!param)
		return (-1);
	va_start(ap, param);
	count = 0;
	i = 0;
	while (param[i] != '\0')
	{
		if (param[i] != '%')
			count += ft_putchar(param[i]);
		if (count == -1)
			return (count);
		else if (param[i] == '%' && param[i + 1] != '\0')
		{
			i++;
			count += ft_dealing_format(param[i], ap);
		}
		i++;
	}
	va_end(ap);
	return ((int)count);
}

size_t	ft_dealing_format(char c, va_list ap)
{
	size_t	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		len += ft_put_str(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		len += ft_put_nbr(va_arg(ap, int));
	else if (c == 'u')
		len += ft_put_uint(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_putnbr_hex(va_arg(ap, unsigned int), c == 'X');
	else if (c == 'p')
		len += ft_putptr(va_arg(ap, void *));
	else if (c == '%')
		len += ft_put_percent();
	return (len);
}

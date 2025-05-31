/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaso <yaso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:21:26 by yaso              #+#    #+#             */
/*   Updated: 2025/05/29 19:05:53 by yaso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_hex(unsigned int n, int is_upper)
{
	char	*base;
	size_t	len;
	int		result;

	result = 0;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_putnbr_hex(n / 16, is_upper);
	result = ft_putchar(base[n % 16]);
	if (result == -1)
		return (result);
	return (len + 1);
}

size_t	ft_putnbr_hex_ull(unsigned long n)
{
	char	*base;
	size_t	len;
	int		result;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += ft_putnbr_hex_ull(n / 16);
	result = ft_putchar(base[n % 16]);
	if (result == -1)
		return(-1);
	len += 1;
	return (len);
}

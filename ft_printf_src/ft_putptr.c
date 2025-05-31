/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaso <yaso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:27:22 by yaso              #+#    #+#             */
/*   Updated: 2025/05/28 17:55:59 by yaso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putptr(void *ptr)
{
	size_t		len;
	uintptr_t	addr;

	if (!ptr)
		return (ft_put_str("(nil)"));
	len = 0;
	addr = (unsigned long)ptr;
	len += ft_put_str("0x");
	len += ft_putnbr_hex_ull(addr);
	return (len);
}

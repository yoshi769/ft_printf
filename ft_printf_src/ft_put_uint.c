/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaso <yaso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:21:00 by yaso              #+#    #+#             */
/*   Updated: 2025/05/29 19:24:13 by yaso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_num_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	size_t	len;
	char	*result;

	len = ft_num_len(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (n != 0)
	{
		result[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (result);
}

size_t	ft_put_uint(unsigned int n)
{
	int	len;
	char	*str;

	len = 0;
	if (n == 0)
		len += ft_putchar('0');
	else
	{
		str = ft_uitoa(n);
		len += ft_put_str(str);
		if (len == -1)
			return (len);
		free(str);
	}
	return (len);
}

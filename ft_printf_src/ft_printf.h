/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaso <yaso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:46:04 by yaso              #+#    #+#             */
/*   Updated: 2025/05/29 19:06:44 by yaso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
size_t	ft_putchar(char c);
size_t	ft_put_str(char *str);
size_t	ft_put_nbr(int n);
size_t	ft_put_percent(void);
size_t	ft_putnbr_hex(unsigned int n, int is_upper);
size_t	ft_putptr(void *ptr);
size_t	ft_put_uint(unsigned int n);
size_t	ft_putnbr_hex_ull(unsigned long n);
char	*ft_itoa(int n);

#endif
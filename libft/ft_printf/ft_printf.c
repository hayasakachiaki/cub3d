/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <maedayukimi@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:52:07 by mawako            #+#    #+#             */
/*   Updated: 2024/10/21 12:39:40 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formatter(va_list *a, const char *s, int i, int len)
{
	if (s[i + 1] == 'c')
		ft_putchar(va_arg(*a, int));
	else if (s[i + 1] == 's')
		len = ft_string(va_arg(*a, char *));
	else if (s[i + 1] == '%')
		ft_putchar('%');
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		ft_putnbr(va_arg(*a, int), &len);
	else if (s[i + 1] == 'u')
		ft_unsigned(va_arg(*a, unsigned int), &len);
	else if (s[i + 1] == 'x' || s[i + 1] == 'X')
		len = ft_hex(va_arg(*a, long), s[i + 1]);
	else if (s[i + 1] == 'p')
		len = ft_address(va_arg(*a, long), 'x');
	else
		ft_putchar(s[i + 1]);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		res;
	va_list	a;

	i = 0;
	res = 0;
	va_start(a, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			res += formatter(&a, s, i++, 0);
		else
			ft_putchar(s[i]);
		res++;
		i++;
	}
	va_end(a);
	return (res);
}

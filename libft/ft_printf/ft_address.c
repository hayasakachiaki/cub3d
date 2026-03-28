/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <maedayukimi@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:12:28 by mawako            #+#    #+#             */
/*   Updated: 2025/08/28 12:10:34 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	len(unsigned long int n, int hexa)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n /= hexa;
		i++;
	}
	return (i);
}

static void	print_address(unsigned long int n, char *base)
{
	if (n < 16)
		ft_putchar(base[n]);
	else
	{
		print_address(n / 16, base);
		print_address(n % 16, base);
	}
}

int	ft_address(unsigned long int n, char c)
{
	char	*base;
	int		length;

	if (n == 0)
		return (ft_string("(nil)"));
	length = ft_string("0x");
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	print_address(n, base);
	return (len(n, 16) + length);
}

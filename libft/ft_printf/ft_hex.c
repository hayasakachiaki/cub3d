/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <maedayukimi@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:44:28 by mawako            #+#    #+#             */
/*   Updated: 2025/08/28 12:10:40 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	len(unsigned int n, int hexa)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= hexa;
		i++;
	}
	return (i);
}

int	ft_hex(unsigned int n, char c)
{
	char	*large;
	char	*x;
	char	*s;

	large = "0123456789ABCDEF";
	x = "0123456789abcdef";
	if (c == 'x')
		s = x;
	else
		s = large;
	if (n < 16)
		ft_putchar(s[n]);
	else
	{
		ft_hex(n / 16, c);
		ft_hex(n % 16, c);
	}
	return (len(n, 16) - 1);
}

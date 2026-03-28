/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <maedayukimi@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:13:34 by mawako            #+#    #+#             */
/*   Updated: 2025/08/28 12:11:08 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_unsigned(unsigned int n, int *len)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_unsigned(n / 10, len);
		ft_unsigned(n % 10, len);
		*len += 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:12:46 by mawako            #+#    #+#             */
/*   Updated: 2025/09/07 00:03:03 by shuu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_string(char *s);
void	ft_unsigned(unsigned int n, int *t);
void	ft_putnbr(int n, int *t);
void	ft_putchar(char c);
int		ft_hex(unsigned int n, char c);
int		ft_address(unsigned long int n, char c);

#endif

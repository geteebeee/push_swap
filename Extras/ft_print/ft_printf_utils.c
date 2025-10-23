/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:56:21 by gorg              #+#    #+#             */
/*   Updated: 2024/04/18 19:46:45 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putcharmod(int c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (1);
}

int	ft_putstrmod(char *s)
{
	int	len;
	int	result;

	len = 0;
	if (s == 0)
	{
		result = write(1, "(null)", 6);
		if (result == -1)
			return (-1);
		return (6);
	}
	while (s[len])
	{
		result = ft_putcharmod(s[len]);
		if (result == -1)
			return (-1);
		len += result;
	}
	return (len);
}

void	ft_hex(char *hex_digits)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		hex_digits[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		hex_digits[i] = (i - 10) + 'a';
		i++;
	}
}

int	ft_sign(long long *nbr, const char format)
{
	if (*nbr < 0 && (format != 'x' && format != 'X' && format != 'u'))
	{
		*nbr = -(*nbr);
		return (ft_putcharmod('-'));
	}
	return (0);
}

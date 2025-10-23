/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:56:21 by gorg              #+#    #+#             */
/*   Updated: 2024/07/15 23:42:24 by gorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putdigit(long long nbr, const char format)
{
	if (format == 'x' && nbr > 9)
		return (ft_putcharmod(nbr + 'a' - 10));
	else if (format == 'X' && nbr > 9)
		return (ft_putcharmod(nbr + 'A' - 10));
	else
		return (ft_putcharmod(nbr + '0'));
}

static int	ft_putnbrmod(long long nbr, const char format, int n)
{
	int	len;

	len = 0;
	if (format == 'u' || format == 'x' || format == 'X')
		nbr = (unsigned int)nbr;
	len = ft_sign(&nbr, format);
	if (len == -1)
		return (-1);
	if (nbr >= n)
	{
		len += ft_putnbrmod(nbr / n, format, n);
		if (len == -1)
			return (-1);
		return (len + ft_putnbrmod(nbr % n, format, n));
	}
	return (len + ft_putdigit(nbr, format));
}

static int	ft_putptr(void *ptr)
{
	int			len;
	uintptr_t	num;
	int			i;
	char		hex_digits[16];

	ft_hex(hex_digits);
	num = (uintptr_t)ptr;
	if (num == 0)
		return (ft_putstrmod("(nil)"));
	len = write(1, "0x", 2);
	if (len == -1)
		return (-1);
	i = (sizeof(uintptr_t) * 8) - 4;
	while (i > 0 && ((num >> i) & 0xF) == 0)
		i -= 4;
	while (i >= 0)
	{
		len += ft_putcharmod(hex_digits[(num >> i) & 0xF]);
		if (len == -1)
			return (-1);
		i -= 4;
	}
	return (len);
}

static int	ft_formating(va_list args, const char **format)
{
	int	check;

	(*format)++;
	if (**format == 'c')
		check = ft_putcharmod(va_arg(args, int));
	else if (**format == 's')
		check = ft_putstrmod(va_arg(args, char *));
	else if (**format == 'p')
		check = ft_putptr(va_arg(args, void *));
	else if (**format == 'd' || **format == 'i')
		check = ft_putnbrmod(va_arg(args, int), **format, 10);
	else if (**format == 'u')
		check = ft_putnbrmod(va_arg(args, unsigned int), **format, 10);
	else if (**format == 'X' || **format == 'x')
		check = ft_putnbrmod(va_arg(args, unsigned int), **format, 16);
	else if (**format == '%')
		check = ft_putcharmod('%');
	else
		check = -1;
	(*format)++;
	return (check);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		check;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			check = ft_formating(args, &format);
		else
			check = ft_putcharmod(*format++);
		if (check == -1)
		{
			va_end(args);
			return (-1);
		}
		len += check;
	}
	va_end(args);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:56:21 by gorg              #+#    #+#             */
/*   Updated: 2024/04/18 19:46:45 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_putstrmod(char *s);
int		ft_putcharmod(int c);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_hex(char *hex_digits);
int		ft_sign(long long *nbr, const char format);
#endif

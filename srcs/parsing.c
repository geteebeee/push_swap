/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:21:13 by gorg              #+#    #+#             */
/*   Updated: 2025/01/04 01:48:58 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_free_split(char **split)
{
	int	i;

	if (split)
	{
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
	}
}

int	ft_duplicates(t_lst **stacka)
{
	t_lst	*cur;
	t_lst	*check;

	cur = *stacka;
	while (cur)
	{
		check = cur->next;
		while (check != NULL)
		{
			if (cur->content == check->content)
				return (-1);
			check = check->next;
		}
		cur = cur->next;
	}
	return (0);
}

int	ft_check(char *str)
{
	int	found;

	found = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == '+' || *str == '-')
		{
			str++;
			if (*str < '0' || *str > '9')
				return (-1);
		}
		while (*str >= '0' && *str <= '9')
		{
			found = 1;
			str++;
		}
		if (*str != ' ' && *str != '\0')
			return (-1);
	}
	if (!found)
		return (-1);
	return (0);
}

static int	atoirun(const char *str, long long res, int sign, int *error_flag)
{
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && - res < INT_MIN))
		{
			*error_flag = 1;
			return (0);
		}
		str++;
	}
	return ((int)(res * sign));
}

int	ft_atoi_mod(const char *str, int *error_flag)
{
	long long	res;
	int			sign;

	*error_flag = 0;
	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
	{
		*error_flag = 1;
		return (0);
	}
	return (atoirun(str, res, sign, error_flag));
}

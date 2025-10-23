/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:27:37 by gorg              #+#    #+#             */
/*   Updated: 2024/12/17 17:32:58 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ft_max(t_lst **stack)
{
	int		number;
	t_lst	*temp;
	int		index;

	if (!stack)
		return (0);
	temp = *stack;
	number = temp->content;
	index = temp->index;
	while (temp)
	{
		if (temp->content > number)
		{
			number = temp->content;
			index = temp->index;
		}
		temp = temp->next;
	}
	return (index);
}

static int	ft_binary_len(int max)
{
	int	blen;

	blen = 0;
	while ((max >> blen) != 0)
		blen++;
	return (blen);
}

void	ft_radix(t_lst **stacka, t_lst **stackb, int size)
{
	int	max;
	int	blen;
	int	i;
	int	j;

	i = 0;
	max = ft_max(stacka);
	blen = ft_binary_len(max);
	while (i < blen)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stacka)->index >> i) & 1) == 1)
			{
				ft_rarb(stacka, 1);
			}
			else
				ft_papb(stacka, stackb, 1);
			j++;
		}
		while (*stackb)
			ft_papb(stackb, stacka, 2);
		i++;
	}
}

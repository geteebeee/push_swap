/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:24:39 by gorg              #+#    #+#             */
/*   Updated: 2024/12/17 17:30:56 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_smalersort(t_lst **stacka, int one, int two, int tri)
{
	if (one > two && two > tri)
	{
		ft_sasb(stacka, 1);
		ft_rrarrb(stacka, 1);
	}
	else if (one > tri && tri > two)
		ft_rarb(stacka, 1);
	else if (two > one && one > tri)
		ft_rrarrb(stacka, 1);
	else if (one > two && tri > one)
		ft_sasb(stacka, 1);
	else if (two > tri && tri > one)
	{
		ft_sasb(stacka, 1);
		ft_rarb(stacka, 1);
	}
}

static void	ft_smallsort(t_lst **stacka, int size)
{
	int	one;
	int	two;
	int	tri;

	one = (int)(*stacka)->content;
	two = (int)(*stacka)->next->content;
	tri = 0;
	if (size == 2 && one > two)
		ft_sasb(stacka, 1);
	if (size == 3)
	{
		tri = (int)(*stacka)->next->next->content;
		ft_smalersort(stacka, one, two, tri);
	}
}

static int	ft_num_pos(t_lst **stack)
{
	int		number;
	int		num_pos;
	int		i;
	t_lst	*temp;

	if (!stack)
		return (0);
	temp = *stack;
	number = temp->content;
	num_pos = 0;
	i = 0;
	while (temp)
	{
		if (temp->content < number)
		{
			number = temp->content;
			num_pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (num_pos);
}

static void	ft_positioning(t_lst **stacka, int num_pos, int size)
{
	if (num_pos <= size / 2)
	{
		while (num_pos != 0)
		{
			ft_rarb(stacka, 1);
			num_pos--;
		}
	}
	else
	{
		while (num_pos < size)
		{
			ft_rrarrb(stacka, 1);
			num_pos++;
		}
	}
}

void	ft_manual(t_lst **stacka, t_lst **stackb, int size)
{
	int	i;

	if (size == 2 || size == 3)
	{
		ft_smallsort(stacka, size);
		return ;
	}
	else
	{
		while (size > 3)
		{
			i = ft_num_pos(stacka);
			ft_positioning(stacka, i, size);
			ft_papb(stacka, stackb, 1);
			size--;
		}
		ft_smallsort(stacka, size);
		while (*stackb)
			ft_papb(stackb, stacka, 2);
	}
}

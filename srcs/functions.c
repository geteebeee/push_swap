/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:40:16 by gorg              #+#    #+#             */
/*   Updated: 2024/12/17 17:22:11 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_sasb(t_lst **stack, int n)
{
	int	temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	if (n == 1)
		ft_printf("sa\n");
	if (n == 2)
		ft_printf("sb\n");
}

void	ft_papb(t_lst **stacka, t_lst **stackb, int n)
{
	t_lst	*temp;

	if (!stacka || !*stacka)
		return ;
	temp = *stacka;
	*stacka = (*stacka)->next;
	if (*stacka)
		(*stacka)->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	ft_lstadd_fronts(stackb, temp);
	if (n == 2)
		ft_printf("pa\n");
	if (n == 1)
		ft_printf("pb\n");
}

int	ft_lstsizes(t_lst *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}

void	ft_rarb(t_lst **stack, int n)
{
	t_lst	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	ft_lstadd_backs(stack, temp);
	if (n == 1)
		ft_printf("ra\n");
	if (n == 2)
		ft_printf("rb\n");
}

void	ft_rrarrb(t_lst **stack, int n)
{
	t_lst	*temp;
	t_lst	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = ft_lstlasts(*stack);
	prev = temp->prev;
	prev->next = NULL;
	ft_lstadd_fronts(stack, temp);
	if (n == 1)
		ft_printf("rra\n");
	if (n == 2)
		ft_printf("rrb\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:31:26 by gorg              #+#    #+#             */
/*   Updated: 2024/12/17 17:36:43 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ft_sorted(t_lst **stacka)
{
	t_lst	*temp;
	int		i;

	i = 0;
	temp = *stacka;
	while (temp != NULL && temp->next != NULL)
	{
		if (i != temp->index)
			return (-1);
		i++;
		temp = temp->next;
	}
	return (1);
}

static void	ft_index(t_lst *stack)
{
	t_lst	*temp1;
	t_lst	*temp2;
	int		index;

	temp1 = stack;
	while (temp1)
	{
		index = 0;
		temp2 = stack;
		while (temp2)
		{
			if (temp1->content > temp2->content)
				index++;
			temp2 = temp2->next;
		}
		temp1->index = index;
		temp1 = temp1->next;
	}
}

static void	ft_sorter(t_lst **stacka, t_lst **stackb)
{
	int	size;

	size = ft_lstsizes(*stacka);
	ft_index(*stacka);
	if (ft_sorted(stacka) == 1 || size == 1)
		return ;
	else if (size <= 5)
		ft_manual(stacka, stackb, size);
	else
		ft_radix(stacka, stackb, size);
}

static void	error(t_lst **stacka)
{
	if (stacka && *stacka)
		ft_lstclears(stacka);
	if (stacka)
		free(stacka);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_lst	**stacka;
	t_lst	**stackb;

	if (argc < 2)
		return (-1);
	stacka = (t_lst **)malloc(sizeof(t_lst *));
	if (!stacka)
		error(stacka);
	*stacka = NULL;
	if (ft_validate_and_append(argc, argv, stacka) == -1)
		error(stacka);
	stackb = (t_lst **)malloc(sizeof(t_lst *));
	if (!stackb)
		error(stacka);
	*stackb = NULL;
	ft_sorter(stacka, stackb);
	ft_lstclears(stacka);
	free(stacka);
	ft_lstclears(stackb);
	free(stackb);
	return (0);
}

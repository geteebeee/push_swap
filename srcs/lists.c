/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:02:32 by gorg              #+#    #+#             */
/*   Updated: 2024/10/13 16:28:44 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_lst	*ft_lstnew_int(int content)
{
	t_lst	*s;

	s = (t_lst *)malloc(sizeof(*s));
	if (!s)
		return (0);
	s->content = content;
	s->next = NULL;
	s->prev = NULL;
	return (s);
}

t_lst	*ft_lstlasts(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_backs(t_lst **lst, t_lst *new)
{
	t_lst	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
		return ;
	}
	temp = ft_lstlasts(*lst);
	temp->next = new;
	new->next = NULL;
	new->prev = temp;
}

void	ft_lstadd_fronts(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	if (*lst != NULL)
		(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}

void	ft_lstclears(t_lst **lst)
{
	t_lst	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		free(temp);
	}
	*lst = (NULL);
}

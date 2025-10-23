/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:34:50 by marvin            #+#    #+#             */
/*   Updated: 2024/12/17 17:37:59 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ft_append_loop(t_lst **stacka, char **split)
{
	int		value;
	t_lst	*new;
	int		i;
	int		error_flag;

	i = 0;
	while (split[i])
	{
		value = ft_atoi_mod(split[i++], &error_flag);
		if (error_flag)
		{
			ft_lstclears(stacka);
			return (-1);
		}
		new = ft_lstnew_int(value);
		if (!new)
		{
			ft_lstclears(stacka);
			return (-1);
		}
		ft_lstadd_backs(stacka, new);
	}
	return (0);
}

static int	ft_appender(t_lst **stacka, char *temp)
{
	char	**split;

	split = ft_split(temp, ' ');
	if (!split)
		return (-1);
	if (ft_append_loop(stacka, split) == -1)
	{
		ft_free_split(split);
		return (-1);
	}
	ft_free_split(split);
	if (ft_duplicates(stacka) == -1)
	{
		ft_lstclears(stacka);
		return (-1);
	}
	return (0);
}

static char	*create_temp_string(int argc, char **argv)
{
	char	*temp;
	char	*attach;
	int		i;

	i = 1;
	temp = ft_strdup("");
	if (!temp)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		attach = ft_strjoin(temp, argv[i++]);
		free(temp);
		if (!attach)
			return (NULL);
		temp = ft_strjoin(attach, " ");
		free(attach);
		if (!temp)
			return (NULL);
	}
	return (temp);
}

int	ft_validate_and_append(int argc, char **argv, t_lst **stacka)
{
	char	*temp;

	temp = create_temp_string(argc, argv);
	if (!temp)
		return (-1);
	if (ft_check(temp) == -1 || ft_appender(stacka, temp) == -1)
	{
		free(temp);
		return (-1);
	}
	free(temp);
	return (0);
}

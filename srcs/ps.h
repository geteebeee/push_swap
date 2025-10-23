/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:02:58 by gorg              #+#    #+#             */
/*   Updated: 2024/12/17 17:32:51 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "../Extras/libft/srcs/libft.h"
# include "../Extras/ft_print/ft_printf.h"
# include <limits.h>

typedef struct s_lst
{
	int				content;
	int				index;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

void	ft_sasb(t_lst **stack, int n);
void	ft_papb(t_lst **stacka, t_lst **stackb, int n);
void	ft_rarb(t_lst **stack, int n);
void	ft_rrarrb(t_lst **stack, int n);
int		ft_lstsizes(t_lst *lst);
t_lst	*ft_lstnew_int(int content);
t_lst	*ft_lstlasts(t_lst *lst);
void	ft_lstadd_backs(t_lst **lst, t_lst *new);
void	ft_lstadd_fronts(t_lst **lst, t_lst *new);
void	ft_lstclears(t_lst **lst);
void	ft_manual(t_lst **stacka, t_lst **stackb, int size);
void	ft_free_split(char **split);
int		ft_duplicates(t_lst **stacka);
int		ft_check(char *str);
int		ft_validate_and_append(int argc, char **argv, t_lst **stacka);
void	ft_radix(t_lst **stacka, t_lst **stackb, int size);
int		ft_atoi_mod(const char *str, int *error_flag);

#endif

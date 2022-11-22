/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:50:20 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/22 16:30:20 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	same_coords(t_coords *c1, t_coords *c2, int x, int y)
{
	return ((c1->x == (c2->x + x)) && (c1->y == (c2->y + y)));
}

void	print_tlist(t_list *lst)
{
	int	cpt;

	cpt = 0;
	while (lst->next)
	{
		ft_printf("lst[%d] = (%d,%d)\n", cpt, lst->coords->x, lst->coords->y);
		lst = lst->next;
	}
}

int	is_in(t_list *closed, t_coords *act, int x, int y)
{
	while (closed->next)
	{
		if (same_coords(closed->coords, act, x, y))
			return (1);
		closed = closed->next;
	}
	return (same_coords(closed->coords, act, x, y));
}

int	nbr_move_pos(char **map, t_coords *act)
{
	int	cpt;

	cpt = 0;
	cpt += (ft_strchr("E1", map[act->y][act->x + 1]) == -1);
	cpt += (ft_strchr("E1", map[act->y + 1][act->x]) == -1);
	cpt += (ft_strchr("E1", map[act->y][act->x - 1]) == -1);
	cpt += (ft_strchr("E1", map[act->y - 1][act->x]) == -1);
	return (cpt);
}

int	is_end(char **map, t_player *player, size_t ttcol)
{
	if (map[player->coords->y][player->coords->x] == 'E')
		if (ttcol == player->item_count)
			return (1);
	return (0);
}

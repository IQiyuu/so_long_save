/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:33:39 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/20 18:40:36 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* g_imgs => 0 : sol / 1 : murs / 2 : exit / 3 : player / 4 : items */

int	apply_move(t_player *ply, char ***map, size_t ttcol, mlx_image_t **g_imgs)
{
	size_t	*m_count;
	size_t	p_y;
	size_t	p_x;

	p_y = ply->coords->y;
	p_x = ply->coords->x;
	m_count = &ply->move_count;
	(*m_count)++;
	graph_move_player(ply->coords, g_imgs[3]);
	if ((*map)[p_y][p_x] == 'E' && ply->item_count == ttcol)
	{
		ft_printf("\nmove count : %zu\n%sfin du jeu !!!\n", *m_count, GREEN);
		exit(0);
	}
	else if ((*map)[p_y][p_x] == 'C')
	{
		graph_dispawn_item(ply->coords, g_imgs[4], *map);
		ply->item_count++;
		if (ply->item_count == ttcol)
			ft_printf("vous avez ramase tous les collectibles");
		(*map)[p_y][p_x] = 'c';
	}
	ft_printf("%d\n", *m_count);
	return (1);
}

int	move_left(t_player *player, char **map, size_t ttcol, mlx_image_t **g_imgs)
{
	t_coords	*tmp;

	if (map[player->coords->y][player->coords->x - 1] != '1')
	{
		tmp = player->coords;
		player->coords = new_coords(tmp->x - 1, tmp->y);
		free(tmp);
		apply_move(player, &map, ttcol, g_imgs);
		return (1);
	}
	return (0);
}

int	move_right(t_player *player, char **map, size_t ttcol, mlx_image_t **g_imgs)
{
	t_coords	*tmp;

	if (map[player->coords->y][player->coords->x + 1] != '1')
	{
		tmp = player->coords;
		player->coords = new_coords(tmp->x + 1, tmp->y);
		free(tmp);
		apply_move(player, &map, ttcol, g_imgs);
		return (1);
	}
	return (0);
}

int	move_up(t_player *player, char **map, size_t ttcol, mlx_image_t **g_imgs)
{
	t_coords	*tmp;

	if (map[player->coords->y - 1][player->coords->x] != '1')
	{
		tmp = player->coords;
		player->coords = new_coords(tmp->x, tmp->y - 1);
		free(tmp);
		apply_move(player, &map, ttcol, g_imgs);
		return (1);
	}
	return (0);
}

int	move_down(t_player *player, char **map, size_t ttcol, mlx_image_t **g_imgs)
{
	t_coords	*tmp;

	if (map[player->coords->y + 1][player->coords->x] != '1')
	{
		tmp = player->coords;
		player->coords = new_coords(tmp->x, tmp->y + 1);
		free(tmp);
		apply_move(player, &map, ttcol, g_imgs);
		return (1);
	}
	return (0);
}

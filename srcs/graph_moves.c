/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:26:19 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/20 18:29:40 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graph_dispawn_item(t_coords *p_coords, mlx_image_t *img, char **map)
{
	size_t		cpt;
	size_t		cpt2;
	int			index;

	cpt = 1;
	index = 0;
	while (map[cpt])
	{
		cpt2 = 1;
		while (map[cpt][cpt2])
		{
			if (map[cpt][cpt2] == 'C' || map[cpt][cpt2] == 'c')
				index++;
			if (p_coords->y == cpt && p_coords->x == cpt2)
			{
				img->instances[index - 1].enabled = 0;
				return ;
			}
			cpt2++;
		}
		cpt++;
	}
}

void	graph_move_player(t_coords *p_coords, mlx_image_t *img)
{
	img->instances[0].x = (p_coords->x * 64);
	img->instances[0].y = (p_coords->y * 64);
}

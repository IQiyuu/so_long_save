/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:26:19 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/23 15:43:38 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graph_refresh_mcount(t_graphconf *g_conf)
{
	mlx_delete_image(g_conf->mlx, g_conf->imgs[6]);
	g_conf->m_str = ft_strjoin("moves : ",
			ft_itoa(g_conf->conf->player->move_count++ + 1));
	g_conf->imgs[6] = mlx_put_string(g_conf->mlx, g_conf->m_str, 10, 10);
}

void	graph_refresh_icount(t_graphconf *g_conf)
{
	char	*p1;
	char	*p2;

	mlx_delete_image(g_conf->mlx, g_conf->imgs[7]);
	p1 = ft_strjoin("items : ", ft_itoa(g_conf->conf->player->item_count));
	p2 = ft_strjoin(p1, "/");
	g_conf->i_str = ft_strjoin(p2, ft_itoa(g_conf->conf->collectibles_nbr));
	g_conf->imgs[7] = mlx_put_string(g_conf->mlx, g_conf->i_str,
			(g_conf->conf->x_size - 2) * 64 - 10, 10);
}

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

void	graph_move_ennemy(t_coords *e_coords, mlx_image_t *img, int index)
{
	img->instances[index].x = (e_coords->x * 64);
	img->instances[index].y = (e_coords->y * 64);
}

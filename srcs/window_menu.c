/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:43:31 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/26 22:18:38 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_way(t_graphconf *g_conf)
{
	size_t	cpt;
	int	cpt2;

	cpt = 80;
	while (cpt++ < 1920)
	{
		cpt2 = 0;
		if (g_conf->perso && cpt < 310)
			while (cpt2 < 29)
				mlx_put_pixel(g_conf->imgs[1], cpt + 90, cpt2++ + cpt + 70, 0xFFAE30FF);
		if (g_conf->menu->unlocked_lvls - 1 > cpt / 330 && cpt < 1600)
			while (cpt2 < 21)
				mlx_put_pixel(g_conf->imgs[1], cpt + 90, cpt2++ + 365, 0xFFAE30FF);
		cpt2 = 0;
		if (ft_umax(g_conf->menu->unlocked_lvls, 7) - 7 > cpt/ 350 && cpt < 1800)
			while (cpt2 < 21)
				mlx_put_pixel(g_conf->imgs[1], 1750 - cpt + 58, cpt2++ + 685, 0xFFAE30FF);
	}
	cpt = 400;
	if (g_conf->menu->unlocked_lvls >= 6)
	{
		while (cpt++ < 665)
		{
			cpt2 = 0;
			while (cpt2 < 21)
				mlx_put_pixel(g_conf->imgs[1], 1730 + cpt2++, cpt, 0xFFAE30FF);
		}
	}
}

void	init_round_bis(t_graphconf *g_conf, size_t cpt)
{
	size_t		cpt2;
	t_coords	*act;

	act = g_conf->conf->player->coords;
	cpt2 = cpt;
	while (--cpt > 0)
	{
		if (cpt2++ <= g_conf->menu->unlocked_lvls)
			mlx_image_to_window(g_conf->mlx, g_conf->imgs[3], act->x * 334
				* cpt + (cpt * 3), (g_conf->conf->y_size + 2) * 320);
		else
			mlx_image_to_window(g_conf->mlx, g_conf->imgs[2], act->x * 334
				* cpt + (cpt * 3), (g_conf->conf->y_size + 2) * 320);
	}
}

void	init_menuwin(t_graphconf *g_conf)
{
	t_coords	*act;
	size_t		cpt;

	cpt = 0;
	act = g_conf->conf->player->coords;
	mlx_image_to_window(g_conf->mlx, g_conf->imgs[1], 0, 0);
	if (g_conf->perso != NULL && g_conf->perso_f)
		mlx_image_to_window(g_conf->mlx, g_conf->imgs[2], 95, 95);
	else
		mlx_image_to_window(g_conf->mlx, g_conf->imgs[3], 95, 95);
	while (++cpt < 6)
	{
		if (cpt <= g_conf->menu->unlocked_lvls)
			mlx_image_to_window(g_conf->mlx, g_conf->imgs[3], act->x * 334
				* cpt + (cpt * 3), (g_conf->conf->y_size + 1
					+ (cpt / 6)) * 320);
		else
			mlx_image_to_window(g_conf->mlx, g_conf->imgs[2], act->x * 334
				* cpt + (cpt * 3), (g_conf->conf->y_size + 1
					+ (cpt / 6)) * 320);
	}
	init_round_bis(g_conf, cpt);
	init_way(g_conf);
}

void	win_menu(t_graphconf *g_conf)
{
	g_conf->in_game = 0;
	g_conf->conf = init_map_struct();
	g_conf->conf->player = new_player(new_coords(1, 0));
	delete_imgs(g_conf, 1, 13);
	g_conf->anims[1] = NULL;
	g_conf->anims[2] = NULL;
	g_conf->anims[3] = NULL;
	g_conf->anims[0]->enable = 1;
	init_img(g_conf->mlx, g_conf);
	init_menuwin(g_conf);
	update_player_framez(g_conf, g_conf->imgs[2]->instances[0].z);
}

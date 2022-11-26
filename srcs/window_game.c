/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:48:18 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/26 16:43:35 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* imgs => 0 : sol / 1 : murs / 2 : exit / 3 : player / 4 : items */

int	fill_win(t_graphconf *g_conf, mlx_t *mlx, size_t cpt)
{	
	size_t	cpt2;

	while (++cpt < g_conf->conf->y_size && g_conf->conf->map[cpt])
	{
		cpt2 = -1;
		while (++cpt2 < g_conf->conf->x_size && g_conf->conf->map[cpt][cpt2])
		{
			mlx_image_to_window(mlx, g_conf->imgs[2],
				(W_WIDTH - (g_conf->conf->x_size / 2) * 64) + (cpt2 - 1) * 64,
				(W_HEIGHT - g_conf->conf->y_size) + (cpt - 2) * 64);
			if (g_conf->conf->map[cpt][cpt2] == '1')
				mlx_image_to_window(mlx, g_conf->imgs[3],
					(W_WIDTH - (g_conf->conf->x_size / 2) * 64) + (cpt2 - 1)
					* 64, (W_HEIGHT - g_conf->conf->y_size) + (cpt - 2) * 64);
			if (g_conf->conf->map[cpt][cpt2] == 'C')
				mlx_image_to_window(mlx, g_conf->imgs[5], (W_WIDTH
						- (g_conf->conf->x_size / 2) * 64) + (cpt2 - 1) * 64,
					(W_HEIGHT - g_conf->conf->y_size) + (cpt - 2) * 64);
		}
	}
	mlx_image_to_window(mlx, g_conf->imgs[4], (W_WIDTH - (g_conf->conf->x_size
				/ 2) * 64) + ((g_conf->conf->escap->x - 1) * 64) - 20,
		W_HEIGHT - (g_conf->conf->escap->y) * 64 - 10);
	return (1);
}

void	update_player_framez(t_graphconf *g_conf)
{
	int	cpt;

	cpt = 0;
	while (cpt < 6)
	{
		g_conf->anims[1]->imgs[cpt]->instances[0].z
			= g_conf->imgs[2]->instances[0].z + cpt + 1;
		cpt++;
	}
}

void	init_gameimg(mlx_t *mlx, t_graphconf *g_conf)
{
	g_conf->texts[2] = mlx_load_png(ft_strjoin(IMG_PATH, "grass.png"));
	g_conf->texts[3] = mlx_load_png(ft_strjoin(IMG_PATH, "tree.png"));
	g_conf->texts[4] = mlx_load_png(ft_strjoin(IMG_PATH, "house.png"));
	g_conf->texts[5] = mlx_load_png(ft_strjoin(IMG_PATH, "paper.png"));
	g_conf->texts[6] = mlx_load_png(ft_strjoin(IMG_PATH, "slime/slime0.png"));
	g_conf->texts[7] = mlx_load_png(ft_strjoin(IMG_PATH, "black_bg.png"));
	g_conf->texts[8] = mlx_load_png(ft_strjoin(IMG_PATH, "white_bg.png"));
	check_text_error(g_conf);
	g_conf->imgs[2] = mlx_texture_to_image(mlx, g_conf->texts[2]);
	g_conf->imgs[3] = mlx_texture_to_image(mlx, g_conf->texts[3]);
	g_conf->imgs[4] = mlx_texture_to_image(mlx, g_conf->texts[4]);
	g_conf->imgs[5] = mlx_texture_to_image(mlx, g_conf->texts[5]);
	g_conf->imgs[6] = mlx_texture_to_image(mlx, g_conf->texts[6]);
	g_conf->imgs[7] = mlx_texture_to_image(mlx, g_conf->texts[7]);
	g_conf->imgs[8] = mlx_texture_to_image(g_conf->mlx, g_conf->texts[8]);
}

void	init_gameanim(mlx_t *mlx, t_graphconf *g_conf)
{
	g_conf->anims = (t_animframe **)malloc(sizeof(t_animframe *) * 4);
	g_conf->anims[1] = NULL;
	g_conf->anims[2] = NULL;
	g_conf->anims[3] = NULL;
	//g_conf->anims[4] = NULL;
	g_conf->anims[1] = new_animation("slime/slime", 6, mlx);
	if (!g_conf->anims[1])
		frame_error(g_conf);
	g_conf->anims[2] = new_animation("death/death", 7, mlx);
	if (!g_conf->anims[2])
		frame_error(g_conf);
	g_conf->anims[3] = new_animation("win/win", 6, mlx);
	if (!g_conf->anims[3])
		frame_error(g_conf);
	/*g_conf->anims[4] = new_animation("win/win", 6, mlx);
	if (!g_conf->anims[4])
		frame_error(g_conf);
	*/
	g_conf->anims[1]->enable = 1;
}

int	win_game(t_graphconf *g_conf)
{
	g_conf->in_game = 1;
	g_conf->anims[0]->enable = 1;
	g_conf->conf = init_map(g_conf->sel_map);
	g_conf->i_str = ft_strjoin("Items : 0/", ft_itoa(g_conf->conf->collectibles_nbr));
	if (!g_conf->conf)
		end_game_bis(g_conf, 0);
	g_conf->imgs[10]->enabled = 0;
	g_conf->imgs[3]->enabled = 0;
	fill_win(g_conf, g_conf->mlx, -1);
	update_player_framez(g_conf);
	init_graph_player(g_conf);
	init_graph_enemies(g_conf, g_conf->mlx, 0);
	g_conf->imgs[9] = mlx_put_string(g_conf->mlx, g_conf->m_str, 10, 0);
	g_conf->imgs[10] = mlx_put_string(g_conf->mlx, g_conf->i_str,
			W_WIDTH * 2 - 124, 0);
	return (EXIT_SUCCESS);
}

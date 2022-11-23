/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:48:18 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/23 16:16:41 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* imgs => 0 : sol / 1 : murs / 2 : exit / 3 : player / 4 : items */

int	fill_win(t_graphconf *g_conf, mlx_t *mlx)
{	
	size_t	cpt;
	size_t	cpt2;

	cpt = -1;
	while (++cpt < g_conf->conf->y_size && g_conf->conf->map[cpt])
	{
		cpt2 = -1;
		while (++cpt2 < g_conf->conf->x_size && g_conf->conf->map[cpt][cpt2])
		{
			mlx_image_to_window(mlx, g_conf->imgs[0], cpt2 * 64, cpt * 64);
			if (g_conf->conf->map[cpt][cpt2] == '1')
				mlx_image_to_window(mlx, g_conf->imgs[1], cpt2 * 64, cpt * 64);
			if (g_conf->conf->map[cpt][cpt2] == 'C')
				mlx_image_to_window(mlx, g_conf->imgs[4], cpt2 * 64, cpt * 64);
		}
	}
	mlx_image_to_window(mlx, g_conf->imgs[2], g_conf->conf->escap->x * 64 - 20,
		g_conf->conf->escap->y * 64);
	init_graph_player(g_conf);
	return (1);
}

void	move_manager(mlx_key_data_t keydata, void *param)
{
	t_graphconf	*g_conf;
	static int	end = 0;

	g_conf = (t_graphconf *)param;
	if (keydata.action != MLX_RELEASE)
		end = key_manager(g_conf, keydata);
	if (end)
		end_game(g_conf, 1);
}

void	init_img(mlx_t *mlx, t_graphconf *g_conf)
{
	g_conf->texts[0] = mlx_load_png(ft_strjoin(IMG_PATH, "grass.png"));
	g_conf->texts[1] = mlx_load_png(ft_strjoin(IMG_PATH, "tree.png"));
	g_conf->texts[2] = mlx_load_png(ft_strjoin(IMG_PATH, "house.png"));
	g_conf->texts[3] = mlx_load_png(ft_strjoin(IMG_PATH, "wizard/wizard0.png"));
	g_conf->texts[4] = mlx_load_png(ft_strjoin(IMG_PATH, "paper.png"));
	g_conf->texts[5] = mlx_load_png(ft_strjoin(IMG_PATH, "slime/slime0.png"));
	g_conf->texts[6] = mlx_load_png(ft_strjoin(IMG_PATH, "black_bg.png"));
	g_conf->texts[7] = mlx_load_png(ft_strjoin(IMG_PATH, "white_bg.png"));
	check_text_error(g_conf);
	g_conf->imgs[0] = mlx_texture_to_image(mlx, g_conf->texts[0]);
	g_conf->imgs[1] = mlx_texture_to_image(mlx, g_conf->texts[1]);
	g_conf->imgs[2] = mlx_texture_to_image(mlx, g_conf->texts[2]);
	g_conf->imgs[3] = mlx_texture_to_image(mlx, g_conf->texts[3]);
	g_conf->imgs[4] = mlx_texture_to_image(mlx, g_conf->texts[4]);
	g_conf->imgs[5] = mlx_texture_to_image(mlx, g_conf->texts[5]);
	g_conf->imgs[8] = mlx_texture_to_image(g_conf->mlx, g_conf->texts[6]);
	g_conf->imgs[9] = mlx_texture_to_image(g_conf->mlx, g_conf->texts[7]);
}

void	init_anim(mlx_t *mlx, t_graphconf *g_conf)
{
	g_conf->anims = (t_animframe **)malloc(sizeof(t_animframe *) * 4);
	g_conf->anims[1] = NULL;
	g_conf->anims[2] = NULL;
	g_conf->anims[3] = NULL;
	g_conf->anims[0] = new_animation("slime/slime", 9, mlx);
	if (!g_conf->anims[0])
		frame_error(g_conf);
	g_conf->anims[1] = new_animation("wizard/wizard", 6, mlx);
	if (!g_conf->anims[1])
		frame_error(g_conf);
	g_conf->anims[2] = new_animation("death/death", 7, mlx);
	if (!g_conf->anims[2])
		frame_error(g_conf);
	g_conf->anims[3] = new_animation("win/win", 6, mlx);
	if (!g_conf->anims[3])
		frame_error(g_conf);
	g_conf->anims[0]->enable = 1;
	g_conf->anims[1]->enable = 1;
}

int	win_init(t_mapconf *conf)
{
	mlx_t			*mlx;
	mlx_image_t		**imgs;
	mlx_texture_t	**texts;
	t_graphconf		*g_conf;

	mlx = mlx_init(conf->x_size * 64, conf->y_size * 64, "sline_attak", true);
	texts = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *) * NBR_TEXTS);
	imgs = (mlx_image_t **)malloc(sizeof(mlx_image_t *) * NBR_IMGS);
	g_conf = new_graphconf(conf, imgs, texts, mlx);
	init_img(mlx, g_conf);
	if (!mlx)
		return (EXIT_FAILURE);
	init_anim(mlx, g_conf);
	fill_win(g_conf, mlx);
	init_graph_enemies(g_conf, mlx, 0);
	mlx_loop_hook(mlx, &animation_manager, g_conf);
	mlx_key_hook(mlx, &move_manager, g_conf);
	g_conf->imgs[6] = mlx_put_string(mlx, g_conf->m_str, 10, 10);
	g_conf->imgs[7] = mlx_put_string(mlx, g_conf->i_str,
			(conf->x_size - 2) * 64 - 10, 10);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

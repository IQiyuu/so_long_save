/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:48:23 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/26 16:47:07 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_manager(mlx_key_data_t keydata, void *param)
{
	t_graphconf	*g_conf;
	static int	end = 0;

	g_conf = (t_graphconf *)param;
	if (keydata.action != MLX_RELEASE && g_conf->in_game)
		end = key_manager(g_conf, keydata);
	else if (!g_conf->in_game)
		menukey_manager(g_conf, keydata);
	if (keydata.key == MLX_KEY_ESCAPE)
		end_game(g_conf, 0);
	if (end)
		end_game(g_conf, 1);
}

void	init_img(mlx_t *mlx, t_graphconf *g_conf)
{
	g_conf->texts[0] = mlx_load_png(ft_strjoin(IMG_PATH, "wizard/wizard0.png"));
	if (g_conf->perso != NULL)
		g_conf->texts[1] = mlx_load_png(ft_strjoin(IMG_PATH, "menu_map_p.png"));
	else
		g_conf->texts[1] = mlx_load_png(ft_strjoin(IMG_PATH, "menu_map.png"));
	check_text_error(g_conf);
	g_conf->imgs[0] = mlx_texture_to_image(mlx, g_conf->texts[0]);
	g_conf->imgs[1] = mlx_texture_to_image(mlx, g_conf->texts[1]);
}

void	init_anim(mlx_t *mlx, t_graphconf *g_conf)
{
	g_conf->anims = (t_animframe **)malloc(sizeof(t_animframe *) * 4);
	g_conf->anims[1] = NULL;
	g_conf->anims[2] = NULL;
	g_conf->anims[3] = NULL;
	//g_conf->anims[4] = NULL;
	g_conf->anims[0] = new_animation("wizard/wizard", 6, mlx);
	if (!g_conf->anims[0])
		frame_error(g_conf);
	g_conf->anims[0]->enable = 1;
}

int	win_init(char *filename)
{
	mlx_image_t		**imgs;
	mlx_texture_t	**texts;
	mlx_t			*mlx;
	t_graphconf		*g_conf;

	mlx = mlx_init(1920, 1080, "slime_attak", true);
	texts = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *) * NBR_TEXTS);
	imgs = (mlx_image_t **)malloc(sizeof(mlx_image_t *) * NBR_IMGS);
	g_conf = new_graphconf(init_map_struct(), imgs, texts, mlx);
	g_conf->menu = malloc(sizeof(t_menu));
	g_conf->menu->unlocked_lvls = 1;
	g_conf->conf->player = new_player(new_coords(1, 0));
	if (filename)
		g_conf->perso = filename;
	init_img(mlx, g_conf);
	if (!mlx)
		return (EXIT_FAILURE);
	init_anim(mlx, g_conf);
	mlx_image_to_window(mlx, g_conf->imgs[1], 0, 0);
	init_graph_player(g_conf);
	mlx_loop_hook(mlx, &animation_manager, g_conf);
	mlx_key_hook(mlx, &move_manager, g_conf);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}

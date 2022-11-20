/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:48:18 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/20 20:18:06 by dgoubin          ###   ########.fr       */
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
	mlx_image_to_window(mlx, g_conf->imgs[3], 
		g_conf->conf->player->coords->x * 64, 
		g_conf->conf->player->coords->y * 64);
	return (1);
}

void	exit_key(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
		ft_printf("END\nreason:\n\tescape pressed\n");
	}
}

void	move_manager(mlx_key_data_t keydata, void *param)
{
	t_graphconf	*g_conf;

	g_conf = (t_graphconf *)param;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action != MLX_RELEASE)
		move_left(g_conf->conf->player, g_conf->conf->map,
			g_conf->conf->collectibles_nbr, g_conf->imgs);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action != MLX_RELEASE)
		move_right(g_conf->conf->player, g_conf->conf->map,
			g_conf->conf->collectibles_nbr, g_conf->imgs);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action != MLX_RELEASE)
		move_down(g_conf->conf->player, g_conf->conf->map,
			g_conf->conf->collectibles_nbr, g_conf->imgs);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action != MLX_RELEASE)
		move_up(g_conf->conf->player, g_conf->conf->map,
			g_conf->conf->collectibles_nbr, g_conf->imgs);
}

int	win_init(t_mapconf *conf)
{
	mlx_t			*mlx;
	mlx_texture_t	*texts[5];
	mlx_image_t		**imgs;
	t_graphconf		*g_conf;

	imgs = (mlx_image_t **)malloc(sizeof(mlx_image_t *) * 7);
	g_conf = new_graphconf(conf, imgs);
	mlx = mlx_init(conf->x_size * 64, conf->y_size * 64, "so_long", true);
	texts[0] = mlx_load_png("img/grass2.png");
	g_conf->imgs[0] = mlx_texture_to_image(mlx, texts[0]);
	texts[1] = mlx_load_png("img/tree.png");
	g_conf->imgs[1] = mlx_texture_to_image(mlx, texts[1]);
	texts[2] = mlx_load_png("img/house.png");
	g_conf->imgs[2] = mlx_texture_to_image(mlx, texts[2]);
	texts[3] = mlx_load_png("img/wizard4.png");
	g_conf->imgs[3] = mlx_texture_to_image(mlx, texts[3]);
	texts[4] = mlx_load_png("img/paper.png");
	g_conf->imgs[4] = mlx_texture_to_image(mlx, texts[4]);
	if (!mlx)
		return (EXIT_FAILURE);
	fill_win(g_conf, mlx);
	mlx_loop_hook(mlx, &exit_key, mlx);
	mlx_key_hook(mlx, &move_manager, g_conf);
	g_conf->imgs[5] = mlx_put_string(mlx, g_conf->m_str, 10, 10);
	g_conf->imgs[6] = mlx_put_string(mlx, g_conf->i_str, (conf->x_size - 2) * 64 - 10, 10);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
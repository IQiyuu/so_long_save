/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:15:52 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/26 22:19:57 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	menukey_manager(t_graphconf *g_conf, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS && !g_conf->in_game)
	{
		if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
			menumove_left(g_conf);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			menumove_right(g_conf);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			menumove_down(g_conf);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			menumove_up(g_conf);
		if (keydata.key == MLX_KEY_ENTER)
		{
			free(g_conf->sel_map);
			if (same_coords(g_conf->conf->player->coords,
					new_coords(0, 0), 0, 0))
					g_conf->sel_map = ft_strdup(g_conf->perso);
			else
				g_conf->sel_map = ft_strjoin(ft_strjoin("maps/lvl",
							ft_itoa(g_conf->conf->player->coords->x
								* (g_conf->conf->player->coords->y + 1))),
						".ber");
			delete_imgs(g_conf, 1, 4);
			win_game(g_conf);
		}
	}
	return (0);
}

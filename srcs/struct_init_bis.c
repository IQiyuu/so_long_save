/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:39:38 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/26 16:42:33 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_graphconf	*new_graphconf(t_mapconf *conf, mlx_image_t **imgs,
	mlx_texture_t **texts, mlx_t *mlx)
{
	t_graphconf	*g_conf;

	g_conf = (t_graphconf *)malloc(sizeof(t_graphconf));
	g_conf->imgs = imgs;
	g_conf->mlx = mlx;
	g_conf->texts = texts;
	g_conf->conf = conf;
	g_conf->m_str = ft_strdup("moves : 0");
	g_conf->i_str = NULL;
	g_conf->anims = NULL;
	g_conf->anim_nbr = 4;
	g_conf->in_game = 0;
	g_conf->perso = NULL;
	g_conf->sel_map = "maps/lvl2.ber";
	return (g_conf);
}

void	init_enemies(t_mapconf *conf)
{
	int		cpt;
	int		cpt2;
	char	**map;

	map = conf->map;
	cpt = 1;
	while (map[cpt])
	{
		cpt2 = 1;
		while (map[cpt][cpt2])
			if (map[cpt][cpt2++] == 'S')
				ft_lstadd_back(&conf->ennemies, new_coords(cpt2 - 1, cpt));
		cpt++;
	}
}

void	init_graph_player(t_graphconf *g_conf)
{
	mlx_image_t	*img;
	int			cpt;
	t_coords	*act;

	act = g_conf->conf->player->coords;
	cpt = -1;
	while (++cpt < 6)
	{
		img = g_conf->anims[1]->imgs[cpt];
		mlx_image_to_window(g_conf->mlx, img,
			(g_conf->conf->player->coords->x * 342),
			((g_conf->conf->player->coords->y + 1) * 320));
		if (cpt != 0)
			img->instances[0].enabled = 0;
	}
}

void	init_graph_enemies(t_graphconf *g_conf, mlx_t *mlx, int index)
{
	size_t		cpt;
	size_t		cpt2;
	int			cpt3;
	mlx_image_t	*img;

	cpt = -1;
	while (++cpt < g_conf->conf->y_size && g_conf->conf->map[cpt])
	{
		cpt2 = -1;
		while (++cpt2 < g_conf->conf->x_size && g_conf->conf->map[cpt][cpt2])
		{
			if (g_conf->conf->map[cpt][cpt2] == 'S')
			{
				cpt3 = -1;
				while (++cpt3 < 9)
				{
					img = g_conf->anims[6]->imgs[cpt3];
					index = mlx_image_to_window(mlx, img,
							cpt2 * 64, (cpt * 64) + 15);
					if (cpt3 != 0)
						img->instances[index].enabled = 0;
				}
			}
		}
	}
}

t_animframe	*new_animation(char *base_filename, int size, mlx_t *mlx)
{
	t_animframe	*new_anim;
	int			cpt;
	char		*tmp;

	cpt = 0;
	new_anim = (t_animframe *)malloc(sizeof(t_animframe));
	new_anim->enable = 0;
	new_anim->texts = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *) * size);
	new_anim->imgs = (mlx_image_t **)malloc(sizeof(mlx_image_t *) * size);
	while (cpt < size)
	{
		tmp = ft_strjoin(base_filename, ft_itoa(cpt));
		tmp = ft_strjoin(tmp, ".png");
		new_anim->texts[cpt] = mlx_load_png(ft_strjoin(IMG_PATH, tmp));
		if (new_anim->texts[cpt] == NULL)
			return (free_anim(mlx, new_anim));
		new_anim->imgs[cpt] = mlx_texture_to_image(mlx, new_anim->texts[cpt]);
		cpt++;
	}
	new_anim->count = 0;
	new_anim->size = size;
	new_anim->index = 0;
	return (new_anim);
}

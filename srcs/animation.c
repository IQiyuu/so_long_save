/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:46:50 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/22 18:37:22 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_manager(void *param)
{
	t_graphconf	*g_conf;
	int			cpt;
	t_animframe	*anim;

	cpt = -1;
	g_conf = (t_graphconf *)param;
	if (g_conf->anims[3]->enable)
		end_game(g_conf, 1);
	if (ennemy_on_player(g_conf) || g_conf->anims[2]->enable)
		end_game(g_conf, 2);
	while (++cpt < g_conf->anim_nbr - 2)
	{
		anim = g_conf->anims[cpt];
		if (anim->enable)
		{
			if (++anim->count == FRAME_RATE)
			{
				anim->count = 0;
				if (++anim->index == anim->size)
					anim->index = 0;
				update_all_frame(cpt, anim->index, g_conf);
			}
		}
	}
}

void	update_all_frame(int cpt, int old_index, t_graphconf *g_conf)
{
	if (cpt == 0)
		update_ennemies(old_index, g_conf);
	else
		update_player(cpt, old_index, g_conf);
}

void	update_player(int cpt, int old_index, t_graphconf *g_conf)
{
	if (old_index == 0)
		old_index = 5;
	else
		old_index--;
	g_conf->anims[cpt]->imgs[old_index]->instances[0].enabled = 0;
	g_conf->anims[cpt]->imgs[g_conf->anims[1]->index]->instances[0].x
		= (g_conf->conf->player->coords->x * 64);
	g_conf->anims[cpt]->imgs[g_conf->anims[1]->index]->instances[0].y
		= (g_conf->conf->player->coords->y * 64);
	g_conf->anims[cpt]->imgs[g_conf->anims[1]->index]->instances[0].enabled = 1;
}

void	update_ennemies(int old_index, t_graphconf *g_conf)
{
	t_list		*ennemies;
	int			cpt;
	t_animframe	*anim;

	anim = g_conf->anims[0];
	if (old_index == 0)
		old_index = 8;
	else
		old_index--;
	cpt = 0;
	ennemies = g_conf->conf->ennemies;
	while (ennemies)
	{
		anim->imgs[old_index]->instances[cpt].enabled = 0;
		anim->imgs[anim->index]->instances[cpt].x
			= (ennemies->coords->x * 64);
		anim->imgs[anim->index]->instances[cpt].y
			= (ennemies->coords->y * 64 + 15);
		anim->imgs[anim->index]->instances[cpt++].enabled = 1;
		ennemies = ennemies->next;
	}
}

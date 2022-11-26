/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:54:48 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/22 13:39:27 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	default_move(t_graphconf *g_conf, t_list *ennemy, int cpt)
{
	char		**map;
	t_coords	*act;

	map = g_conf->conf->map;
	act = ennemy->coords;
	if (ft_strchr("E1S", map[act->y][act->x + 1]) == -1)
		apply_ennemies_moves(ennemy, new_coords(act->x + 1, act->y),
			g_conf, cpt);
	else if (ft_strchr("E1S", map[act->y][act->x - 1]) == -1)
		apply_ennemies_moves(ennemy, new_coords(act->x - 1, act->y),
			g_conf, cpt);
	else if (ft_strchr("E1S", map[act->y + 1][act->x]) == -1)
		apply_ennemies_moves(ennemy, new_coords(act->x, act->y + 1),
			g_conf, cpt);
	else if (ft_strchr("E1S", map[act->y - 1][act->x]) == -1)
		apply_ennemies_moves(ennemy, new_coords(act->x, act->y - 1),
			g_conf, cpt);
}

void	apply_ennemies_moves(t_list *ennemy, t_coords *new_coords,
			t_graphconf *g_conf, int cpt)
{
	free(ennemy->coords);
	ennemy->coords = new_coords;
	graph_move_ennemy(ennemy->coords,
		g_conf->anims[0]->imgs[g_conf->anims[0]->index], cpt);
}

void	random_move(int x, t_list *ennemies, t_graphconf *g_conf, int cpt)
{
	char		**map;
	t_coords	*act;

	map = g_conf->conf->map;
	act = ennemies->coords;
	x = rand() % ((nbr_move_pos(g_conf->conf->map, act)) + 1);
	if (x-- <= 0 && (ft_strchr("E1", map[act->y][act->x + 1]) == -1))
		apply_ennemies_moves(ennemies, new_coords(act->x + 1, act->y),
			g_conf, cpt);
	else if (x-- <= 0 && (ft_strchr("E1", map[act->y][act->x - 1]) == -1))
		apply_ennemies_moves(ennemies, new_coords(act->x - 1, act->y),
			g_conf, cpt);
	else if (x-- <= 0 && (ft_strchr("E1", map[act->y + 1][act->x]) == -1))
		apply_ennemies_moves(ennemies, new_coords(act->x, act->y + 1),
			g_conf, cpt);
	else if (x-- <= 0 && (ft_strchr("E1", map[act->y - 1][act->x]) == -1))
		apply_ennemies_moves(ennemies, new_coords(act->x, act->y - 1),
			g_conf, cpt);
	else if (x < 0)
		default_move(g_conf, ennemies, cpt);
}

void	gen_ennemies_moves(t_graphconf *g_conf)
{
	t_list		*ennemies;
	t_coords	*act;
	int			cpt;

	cpt = 0;
	ennemies = g_conf->conf->ennemies;
	while (ennemies)
	{
		act = ennemies->coords;
		if (nbr_move_pos(g_conf->conf->map, ennemies->coords) > 0)
			random_move(0, ennemies, g_conf, cpt);
		cpt++;
		ennemies = ennemies->next;
	}
}

int	ennemy_on_player(t_graphconf *g_conf)
{
	t_list	*ennemy;

	ennemy = g_conf->conf->ennemies;
	while (ennemy)
	{
		if (same_coords(ennemy->coords, g_conf->conf->player->coords, 0, 0))
			return (1);
		ennemy = ennemy->next;
	}
	return (0);
}

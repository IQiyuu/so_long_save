/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reef.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:49:50 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/18 19:01:57 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mapconf	*free_conf(t_mapconf *conf)
{
	size_t	cpt;

	if (conf != NULL)
	{
		cpt = 0;
		if (conf->map != NULL)
			while (conf->map[cpt] != NULL)
				free(conf->map[cpt++]);
		if (conf->player != NULL)
			free_player(conf->player);
		if (conf->escap)
			free(conf->escap);
		free(conf);
	}
	return (NULL);
}

t_player	*free_player(t_player *player)
{
	if (player->coords)
		free(player->coords);
	free(player);
	return (NULL);
}

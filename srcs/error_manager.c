/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:26:25 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/26 18:28:24 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_text_error(t_graphconf *g_conf, int nb)
{
	int	cpt;

	cpt = 0;
	while (cpt < nb)
	{
		if (!g_conf->texts[cpt++])
		{
			free_gconf(g_conf);
			exit(EXIT_FAILURE);
		}
	}
}

void	frame_error(t_graphconf *g_conf)
{
	free_gconf(g_conf);
	exit(EXIT_FAILURE);
}

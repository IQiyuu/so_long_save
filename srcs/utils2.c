/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:42:11 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/26 18:58:15 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texts_null(t_graphconf *g_conf, int start, int end)
{
	while (start < end)
		g_conf->texts[start++] = NULL;
}

void	imgs_null(t_graphconf *g_conf, int start, int end)
{
	while (start < end)
		g_conf->imgs[start++] = NULL;
}

void	delete_imgs(t_graphconf *g_conf, int start, int end)
{
	while (start < end)
		mlx_delete_image(g_conf->mlx, g_conf->imgs[start++]);
}

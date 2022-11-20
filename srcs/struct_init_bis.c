/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:39:38 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/20 20:18:41 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_graphconf	*new_graphconf(t_mapconf *conf, mlx_image_t **imgs)
{
	t_graphconf	*g_conf;

	g_conf = (t_graphconf *)malloc(sizeof(t_graphconf));
	g_conf->imgs = imgs;
	g_conf->conf = conf;
	g_conf->m_str = "moves : 0";
	g_conf->i_str = ft_strjoin("Item : 0/", ft_itoa(conf->collectibles_nbr));
	return (g_conf);
}
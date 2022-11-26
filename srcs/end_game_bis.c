/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:26:46 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/25 20:27:39 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game_bis(t_graphconf *g_conf, int opt)
{

	if (opt == 0)
	{
		ft_printf(MERROR);
		free_gconf(g_conf);
		exit(MLX_SUCCESS);
	}
}
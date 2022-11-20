/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:42:17 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/20 20:05:21 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

typedef struct s_player
{
	t_coords	*coords;
	size_t		item_count;
	size_t		move_count;
}	t_player;

typedef struct s_mapconf
{
	size_t		x_size;
	size_t		y_size;
	t_player	*player;
	size_t		collectibles_nbr;
	char		**map;
	t_coords	*escap;
}	t_mapconf;

typedef struct s_graphconf
{
	t_mapconf	*conf;
	mlx_image_t	**imgs;
	char		*i_str;
	char		*m_str;
}	t_graphconf;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:32:04 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/22 14:45:44 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mapconf	*conf;

	srand(time(NULL));
	if (argc == 2)
		conf = init_map(ft_strjoin(MAP_PATH, argv[1]));
	else
		conf = init_map(ft_strjoin(MAP_PATH, "map.ber"));
	if (!conf)
	{
		ft_printf("MAP ERROR");
		return (0);
	}
	win_init(conf);
	return (0);
}
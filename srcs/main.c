/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:32:04 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/23 17:08:09 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_name(char *str)
{
	if (ft_strrchr(str, '.') == NULL)
	{
		ft_printf("no file extension found, use a .ber file");
		exit(EXIT_FAILURE);
	}
	else if (ft_strncmp(ft_strrchr(str, '.'), ".ber", 4) != 0)
	{
		ft_printf("bad extension, %s don't work instead use .ber",
			ft_strrchr(str, '.'));
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_mapconf	*conf;

	srand(time(NULL));
	if (argc == 2)
	{
		check_file_name(argv[1]);
		ft_printf("launching specified map: %s\n",
			ft_strjoin(MAP_PATH, argv[1]));
		conf = init_map(ft_strjoin(MAP_PATH, argv[1]));
	}
	else
	{
		ft_printf("launching default map: %s\n",
			ft_strjoin(MAP_PATH, "map.ber"));
		conf = init_map(ft_strjoin(MAP_PATH, "map.ber"));
	}
	if (!conf)
	{
		ft_printf("MAP ERROR");
		return (EXIT_FAILURE);
	}
	win_init(conf);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:12 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/20 20:08:19 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "struct.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // a delete
# include <fcntl.h>

# define MAP_PATH "maps/"

// gestion map
int			fill_map(t_mapconf **conf, char *filename);
size_t		line_is_valid(char *line, t_mapconf *conf, size_t cpt);
int			encapsuled(t_mapconf *conf);
t_mapconf	*init_map(char *filename);

// pathfinder
int			find_way_init(t_mapconf *conf);
int			find_way(char **map, t_coords *act, t_list **closed, int *args);

// moves
int			move_right(t_player *player, char **map, size_t ttcol,
				mlx_image_t **g_imgs);
int			move_up(t_player *player, char **map, size_t ttcol,
				mlx_image_t **g_imgs);
int			move_down(t_player *player, char **map, size_t ttcol,
				mlx_image_t **g_imgs);
int			move_left(t_player *player, char **map, size_t ttcol,
				mlx_image_t **g_imgs);
int			apply_move(t_player *player, char ***map, size_t ttcol,
				mlx_image_t **g_imgs);

// utils
int			is_end(char **map, t_player *player, size_t ttcol);
int			nbr_empty_case(char **map);
int			is_in(t_list *closed, t_coords *act, int x, int y);
int			same_coords(t_coords *c1, t_coords *act, int x, int y);
void		print_tlist(t_list *lst);

// term graph
void		print_term_map(char **tab);

// 2D graph
int			fill_win(t_graphconf *conf, mlx_t *mlx);
int			win_init(t_mapconf *conf);
void		graph_dispawn_item(t_coords *p_coords, mlx_image_t *img,
				char **map);
void		graph_move_player(t_coords *p_coords, mlx_image_t *img);

// free fct
t_player	*free_player(t_player *player);
t_mapconf	*free_conf(t_mapconf *conf);

// struct init
void		init_map_struct(t_mapconf **conf);
t_list		*new_list(t_coords *act);
t_coords	*new_coords(int x, int y);
t_player	*new_player(t_coords *coords);
int			*new_args(int col_max);
t_graphconf	*new_graphconf(t_mapconf *conf, mlx_image_t **imgs);

#endif
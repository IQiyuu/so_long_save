/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:36:47 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/21 13:20:14 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_term_map(char **tab)
{
	size_t	cpt;

	cpt = 0;
	while (tab[cpt])
	{
		ft_putstr_fd(tab[cpt++], 1);
		ft_putchar_fd('\n', 1);
	}
	ft_printf("Entrez la direction (asdw / '0' pour quitter) ");
}
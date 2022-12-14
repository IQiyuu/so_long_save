/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_of.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:09:57 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/23 17:09:58 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_of(char *str, char c)
{
	int	cpt;

	cpt = 0;
	while (*str)
		if (*(str++) == c)
			cpt++;
	return (cpt);
}

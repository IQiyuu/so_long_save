/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:38:12 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/01 19:16:16 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	cpt;

	cpt = 0;
	while (s[cpt])
	{
		f(cpt, (s + cpt));
		cpt++;
	}
}

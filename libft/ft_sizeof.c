/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeof_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:26:45 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/09 19:35:18 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_sizeof_i(int n)
{
    int cpt;

    cpt = 0;
    while (n > 9)
    {
        n /= 10;
        cpt++;
    }
    return (cpt + 1);
}

int ft_sizeof_ui(unsigned int n)
{
    int cpt;

    cpt = 0;
    while (n > 9)
    {
        n /= 10;
        cpt++;
    }
    return (cpt + 1);
}
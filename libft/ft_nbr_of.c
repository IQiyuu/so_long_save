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
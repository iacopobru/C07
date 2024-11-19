/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:42:23 by ibrunial          #+#    #+#             */
/*   Updated: 2024/11/18 16:48:56 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	has_duplicates(char *str);

void	ft_putnbr(long long int nb, int n_base, char *c_base, char **dest)
{
	char	digit;

	if (nb < 0)
	{
		**dest = '-';
		(*dest)++;
		nb = -nb;
	}
	if (nb >= n_base)
	{
		ft_putnbr(nb / n_base, n_base, c_base, dest);
	}
	digit = c_base[nb % n_base];
	**dest = digit;
	(*dest)++;
}

int	ft_putnbr_base(int nbr, char *base, char *dest)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (base[i] <= 32 || base[i] == 127)
			return (1);
		i++;
	}
	if (has_duplicates(base))
		return (1);
	if (i <= 1)
		return (1);
	ft_putnbr((long long int)nbr, i, base, &dest);
	return (0);
}

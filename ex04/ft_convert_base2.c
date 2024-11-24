/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:42:23 by ibrunial          #+#    #+#             */
/*   Updated: 2024/11/24 18:11:12 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		has_duplicates(char *str);
int		is_in_str(char *str, char c);

int	count_digits(long long int n, int x)
{
	int	d;

	if (n == 0)
		return (1);
	d = 0;
	if (n < 0)
	{
		n = -n;
		d++;
	}
	while (n > 0)
	{
		n = n / x;
		d = d + 1;
	}
	return (d);
}

int	validate_base(char *nbr, char *base_from, char *base_to)
{
	int	i;

	i = -1;
	while (base_from[++i] != '\0')
		if (base_from[i] == '+' || base_from[i] == '-' || base_from[i] <= 32
			|| base_from[i] == 127)
			return (1);
	if (has_duplicates(base_from) || i <= 1)
		return (1);
	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
		i++;
	if (!is_in_str(base_from, nbr[i]))
		return (1);
	i = -1;
	while (base_to[++i] != '\0')
		if (base_to[i] == '+' || base_to[i] == '-' || base_to[i] <= 32
			|| base_to[i] == 127)
			return (1);
	if (has_duplicates(base_to) || i <= 1)
		return (1);
	return (0);
}

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

void	ft_putnbr_base(int nbr, char *base, char *dest)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	ft_putnbr((long long int)nbr, i, base, &dest);
}

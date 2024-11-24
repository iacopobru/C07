/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:40:46 by ibrunial          #+#    #+#             */
/*   Updated: 2024/11/24 18:27:43 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base, char *dest);
int		validate_base(char *nbr, char *base_from, char *base_to);
int		count_digits(long long int n, int x);

int	is_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str, char *base, int size_base)
{
	int	result;
	int	mult;
	int	index;

	mult = 1;
	result = 0;
	index = 0;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			mult = -mult;
		index++;
	}
	while (is_in_str(base, str[index]))
	{
		result = (result * size_base) + (is_in_str(base, str[index]) - 1);
		index++;
	}
	return (result * mult);
}

int	has_duplicates(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (ft_atoi(str, base, i));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*dest;
	int		num;
	int		size_dest;
	int		i;

	if (!nbr || !base_from || !base_to)
		return (NULL);
	if (validate_base(nbr, base_from, base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	i = 0;
	while (base_to[i] != '\0')
		i++;
	size_dest = count_digits((long long int)num, i);
	dest = (char *)malloc(sizeof(char) * size_dest + 1);
	if (!dest)
		return (NULL);
	ft_putnbr_base(num, base_to, dest);
	dest[size_dest] = '\0';
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*nbr;
// 	char	*base_from;
// 	char	*base_to;
// 	char	*result;

// 	nbr = "-1111111111111111111111111111111";
// 	base_from = "01";
// 	base_to = "0123456789";
// 	result = ft_convert_base(nbr, base_from, base_to);
// 	// Output atteso: "97" (se "p=0, o=1, n=2, y=3, v=4, i=5, f=6")
// 	if (result)
// 	{
// 		printf("Risultato: %s\n", result); // Output: Risultato: 5
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Errore nelle basi fornite.\n");
// 	}
// 	return (0);
// }

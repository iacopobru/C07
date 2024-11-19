/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:33:07 by ibrunial          #+#    #+#             */
/*   Updated: 2024/11/18 15:33:22 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*copy_into_location(char **strs, int size, char *sep, int tot_len)
{
	int		j;
	int		i;
	int		len_sep;
	char	*dest;

	i = 0;
	len_sep = ft_strlen(sep);
	dest = (char *)malloc(sizeof(char) * tot_len);
	tot_len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			dest[tot_len++] = strs[i][j];
			j++;
		}
		if (++i != size)
		{
			j = 0;
			while (j < len_sep)
				dest[tot_len++] = sep[j++];
		}
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		tot_len;
	int		len_sep;
	char	*dest;

	if (size <= 0)
	{
		dest = (char *)malloc(sizeof(char));
		*dest = '\0';
		return (dest);
	}
	tot_len = 0;
	i = 0;
	len_sep = 0;
	while (i < size)
		tot_len += ft_strlen(strs[i++]);
	len_sep = ft_strlen(sep);
	tot_len += len_sep * (size - 1) + 1;
	dest = copy_into_location(strs, size, sep, tot_len);
	dest[tot_len] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char msg1[] = "ciao";
// 	char msg2[] = "mi chiamo";
// 	char msg3[] = "iacopo";
// 	char sep[] = " ";
// 	char *strs[3] = {msg1, msg2, msg3};
// 	printf("%s||\n", ft_strjoin(0, strs, sep));
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:33:07 by ibrunial          #+#    #+#             */
/*   Updated: 2024/11/24 18:01:43 by ibrunial         ###   ########.fr       */
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
	dest[tot_len - 1] = '\0';
	return (dest);
}
// int	main(void)
// {
// 	// Test case 1: size = 0 (should return an empty string)
// 	char *result1 = ft_strjoin(0, NULL, ", ");
// 	printf("Test 1 (size = 0): \"%s\"\n", result1);
// 	free(result1);

// 	// Test case 2: size = 1 (should return the only string)
// 	char *strs2[] = {"Hello"};
// 	char *result2 = ft_strjoin(1, strs2, ", ");
// 	printf("Test 2 (size = 1): \"%s\"\n", result2);
// 	free(result2);

// 	// Test case 3: separator is an empty string
// 	char *strs3[] = {"Hello", "World", "Test"};
// 	char *result3 = ft_strjoin(3, strs3, "");
// 	printf("Test 3 (empty separator): \"%s\"\n", result3);
// 	free(result3);

// 	// Test case 4: strs contains empty strings
// 	char *strs4[] = {"Hello", "", "Test"};
// 	char *result4 = ft_strjoin(3, strs4, ", ");
// 	printf("Test 4 (strs with empty strings): \"%s\"\n", result4);
// 	free(result4);

// 	// Test case 5: separator and strs contain empty strings
// 	char *strs5[] = {"", "", ""};
// 	char *result5 = ft_strjoin(3, strs5, "");
// 	printf("Test 5 (empty strs and separator): \"%s\"\n", result5);
// 	free(result5);

// 	// Test case 6: normal case with multiple strings and separator
// 	char *strs6[] = {"Hello", "World", "Test"};
// 	char *result6 = ft_strjoin(3, strs6, ", ");
// 	printf("Test 6 (normal case): \"%s\"\n", result6);
// 	free(result6);

// 	// Test case 7: long strings
// 	char *strs7[] = {"This is a long string.", "Another long string.",
// 		"Yet another long string."};
// 	char *result7 = ft_strjoin(3, strs7, " - ");
// 	printf("Test 7 (long strings): \"%s\"\n", result7);
// 	free(result7);

// 	// Test case 8: separator is NULL (should handle gracefully)
// 	char *strs8[] = {"Hello", "World", "Test"};
// 	char *result8 = ft_strjoin(3, strs8, NULL);
// 	printf("Test 8 (NULL separator): \"%s\"\n", result8);
// 	free(result8);

// 	// Test case 9: strs contains NULL pointers (should handle gracefully)
// 	char *strs9[] = {"Hello", NULL, "Test"};
// 	char *result9 = ft_strjoin(3, strs9, ", ");
// 	printf("Test 9 (strs with NULL pointers): \"%s\"\n", result9);
// 	free(result9);

// 	return (0);
// }
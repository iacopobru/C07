/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:50:57 by ibrunial          #+#    #+#             */
/*   Updated: 2024/11/20 00:09:53 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/////////////////////////////////////
// ATTENZIONE IN TEORIA NON SI PUO USARE FREE
// DEVO RISCRIVERMELA DA CAPO; CALCOLANDO PRIMA LA LUNGHEZZA
/////////////////////////////////////

int	is_in_string(char *str, char c)
{
	while (*str != '\0')
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char	*cp_substr(char *str, int size)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(size + 1);
	if (!dest)
		return (NULL);
	while (str[i] != '\0' && i < size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**cp_arr(char **dest, int size, char *new_element)
{
	char	**f_dest;
	int		i;

	i = 0;
	if (new_element == NULL)
		return (free(dest), NULL);
	f_dest = (char **)malloc(sizeof(char *) * size);
	if (!f_dest)
		return (free(dest), NULL);
	while (i < size - 2)
	{
		f_dest[i] = dest[i];
		i++;
	}
	f_dest[i++] = new_element;
	f_dest[i] = NULL;
	return (free(dest), f_dest);
}

void	init_vars(char ***dest, int *i, int *last, int *sub_str)
{
	*i = 0;
	*last = 0;
	*sub_str = 1;
	*dest = (char **)malloc(sizeof(char *));
	if (!(*dest))
		return ;
	**dest = NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		i;
	int		last;
	int		sub_str;

	init_vars(&dest, &i, &last, &sub_str);
	while (str && charset && is_in_string(charset, str[i]) && str[i++] != '\0')
		last++;
	while (str && charset && str[i] != '\0')
	{
		if (is_in_string(charset, str[i]))
		{
			if (i > last)
				dest = cp_arr(dest, ++sub_str, cp_substr(&str[last], i - last));
			if (!dest)
				return (NULL);
			while (is_in_string(charset, str[i]) && '\0' != str[i++])
				last = i;
		}
		else
			i++;
	}
	if (str && charset && i > last)
		dest = cp_arr(dest, ++sub_str, cp_substr(&str[last], i - last));
	return (dest);
}
// void	print_split_result(char **result)
// {
// 	int	i;

// 	i = 0;
// 	if (result[i] == NULL)
// 		printf("è ritornato nullo\n");
// 	while (result[i] != NULL)
// 	{
// 		printf("Substring %d: '%s'\n", i, result[i]);
// 		free(result[i]); // Dealloca la memoria di ogni sottostringa
// 		i++;
// 	}
// 	free(result); // Dealloca la memoria dell'array
// }

// int	main(void)
// {
// 	// Test 1: Separatore singolo
// 	char str1[] = "hello,world\n";
// 	char charset1[] = "";
// 	printf("Test 1: Separatore singolo\n");
// 	char **result1 = ft_split(str1, charset1);
// 	print_split_result(result1);

// 	// Test 2: Separatore multiplo
// 	char str2[] = "hello,world!42";
// 	char charset2[] = ",!";
// 	printf("\nTest 2: Separatore multiplo\n");
// 	char **result2 = ft_split(str2, charset2);
// 	print_split_result(result2);

// 	// Test 3: Separatore consecutivo
// 	char str3[] = "42:::hello:::world";
// 	char charset3[] = ":";
// 	printf("\nTest 3: Separatore consecutivo\n");
// 	char **result3 = ft_split(str3, charset3);
// 	print_split_result(result3);

// 	// Test 4: Solo separatori
// 	char str4[] = ";;;;";
// 	char charset4[] = ";";
// 	printf("\nTest 4: Solo separatori\n");
// 	char **result4 = ft_split(str4, charset4);
// 	print_split_result(result4);

// 	// Test 5: Nessun separatore
// 	char str5[] = "hello42world";
// 	char charset5[] = ",";
// 	printf("\nTest 5: Nessun separatore\n");
// 	char **result5 = ft_split(str5, charset5);
// 	print_split_result(result5);

// 	// Test 6: Stringa vuota
// 	char str6[] = "";
// 	char charset6[] = "";
// 	printf("\nTest 6: Stringa vuota\n");
// 	char **result6 = ft_split(str6, charset6);
// 	print_split_result(result6);

// 	return (0);
// }
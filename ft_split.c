/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 15:37:17 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/06 20:03:21 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_amount_of_substrings(char const *s, char c)
{
	char	*ptr;
	int		output;
	int		seen;

	output = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		while (*ptr == c)
			ptr++;
		seen = 0;
		while (*ptr && *ptr != c)
		{
			ptr++;
			seen++;
		}
		if (seen)
			++output;
	}
	return (output);
}

static char	**get_output_str(int c_count)
{
	char	**output;

	output = (char **)malloc((c_count + 1) * sizeof(char *));
	if (!output)
		return (NULL);
	output[c_count] = NULL;
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		c_count;
	int		index;
	size_t	start;
	size_t	end;

	c_count = count_amount_of_substrings(s, c);
	output = get_output_str(c_count);
	if (!output)
		return (NULL);
	index = 0;
	start = 0;
	while (c_count--)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		output[index] = (char *)malloc((end - start + 1) * sizeof(char));
		ft_memcpy(output[index], s + start, (end - start));
		output[index++][end - start] = '\0';
		start = end;
	}
	return (output);
}

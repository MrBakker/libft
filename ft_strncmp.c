/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:48:52 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/06 15:03:09 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index] && index < n)
		++index;
	if (index == n)
		return (0);
	return (s1[index] - s2[index]);
}

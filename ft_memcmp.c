/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:29:27 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/09 12:12:09 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	count = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (*ptr1 == *ptr2 && count + 1 < n)
	{
		ptr1++;
		ptr2++;
		count++;
	}
	return (*ptr1 - *ptr2);
}
